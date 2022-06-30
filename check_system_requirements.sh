#!/bin/bash
readonly table_file="system_reqs_table.log"
readonly log_file="system_reqs_results.log"
readonly log_boundary=" | "
# V marks a satisfied requirement.
readonly log_found="V$log_boundary"
# X marks an unsatisfied requirement.
readonly log_missing="X$log_boundary"
readonly log_warning=" $log_boundary"

declare -a apt_reqs

apt_reqs[0]='ffmpeg'
apt_reqs[1]='x11-utils'
apt_reqs[2]='python3-dev'
apt_reqs[3]='python3-pip'
apt_reqs[4]='python3-setuptools'
apt_reqs[5]='virtualenv'
apt_reqs[6]='libgirepository'
apt_reqs[7]='gcc-9'
apt_reqs[8]='g++-9'
apt_reqs[9]='python-gi-dev'
apt_reqs[10]='pkg-config'
apt_reqs[11]='libcairo2-dev'
apt_reqs[12]='libgirepository1.0-dev'
apt_reqs[13]='libgstreamer1.0-dev'
apt_reqs[14]='cmake'
apt_reqs[15]='libgstreamer-plugins-base1.0-dev'


declare -a pkg_config_reqs

pkg_config_reqs[0]='opencv_imgproc'
pkg_config_reqs[1]='opencv_core'
pkg_config_reqs[2]='opencv_imgcodec'

error=false

function check_system_requirements__apt_packages() {
    installed_packages=$(apt list --installed)
    for requirement in ${apt_reqs[@]}
    do
        # Find if the current requirement is installed with apt:
        found="$(( echo $installed_packages | grep $requirement) || echo "X")"
        if [[ $found == "X" ]]; then
            echo "WARNING: Requirement $requirement not found." 1>&2
            echo "$log_warning Missing package: $requirement." >> $log_file
            error=true
        else
            found="V"
            echo "$log_found Package $requirement found." >> $log_file
        fi
        echo -e "Apt-Package\t$requirement\t$found\tRequired" >> $table_file
    done
}

function check_system_requirements__pkg_config(){
    pkg-config opencv4 2> /dev/null
    if [[ $? -ne 0 ]];then
        echo "WARNING: Requirement opencv4 not found." 1>&2
        echo "$log_warning Missing package: opencv4." >> $log_file
        error=true
        found="X"
    else
        found="V"
        echo "$log_found Package opencv4 found." >> $log_file
    fi
    echo -e "Pkg_config-Package\topencv4\t$found\tRequired" >> $table_file
    installed_libs=$(pkg-config --libs opencv4)
    for requirement in ${pkg_config_reqs[@]}
    do
        found="$( echo $installed_libs | grep $requirement 2>/dev/null)"
        if [[ $found == "" ]]; then
            echo "WARNING: Requirement $requirement not found." 1>&2
            echo "$log_warning Missing package: $requirement." >> $log_file
            error=true
            found="X"
        else
            found="V"
            echo "$log_found Package $requrement found." >> $log_file
        fi
        echo -e "Pkg_config-Package\t$requirement\t$found\tRequired" >> $table_file
    done
}

function check_system_requirements__check_gst() {
    gst-inspect-1.0 --gst-version &>>/dev/null
    if [[ $? -ne 0 ]]; then
        echo "WARNING: Requirement Gstreamer not found." 1>&2
        echo "$log_warning Missing package: Gstreamer." >> $log_file
        error=true
        found="X"
    else
        found="V"
        echo "$log_found Package Gstreamer found." >> $log_file
    fi
    echo -e "Package\tGstreamer\t$found\tRequired" >> $table_file
}

function check_system_requirements__print_report() {
    echo -e "\nSYSTEM REQUIREMENTS REPORT\n"
    column -t  $table_file
    echo ""
    echo "See $log_file for more information."
    rm $table_file
    exit 1
}

function check_system_requirements__main() {
    if test -f $table_file; then
        rm $table_file
    fi

    echo -e "Component\tRequirement\tFound" >> $table_file
    echo -e "==========\t==========\t==========\t========== " >> $table_file

    if test -f $log_file; then
        rm $log_file
    fi

    echo -e "HAILO System requirements check - log\n" >> $log_file

    check_system_requirements__apt_packages
    check_system_requirements__pkg_config
    check_system_requirements__check_gst

    if [ "$error" == true  ]; then
        check_system_requirements__print_report
    fi
    rm $table_file
    }

check_system_requirements__main
