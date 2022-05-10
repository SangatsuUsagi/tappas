/**
 * Copyright (c) 2021-2022 Hailo Technologies Ltd. All rights reserved.
 * Distributed under the LGPL license (https://www.gnu.org/licenses/old-licenses/lgpl-2.1.txt)
 **/
#include "hailo_common.hpp"
#include "hailo_objects.hpp"
#include "hailo_tensors.hpp"
#include <string>

#include <pybind11/pybind11.h>
#include <type_traits>

#include <pybind11/numpy.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

namespace py = pybind11;

using namespace pybind11::literals;
using namespace std::string_literals;

using py_descriptor_t = unsigned long;

static HailoMainObjectPtr access_HailoMainObject_from_desc(py_descriptor_t pd)
{
    auto main_obj_pointer = reinterpret_cast<HailoMainObject *>(pd);
    return main_obj_pointer->shared_from_this();
}
static HailoROIPtr access_HailoROI_from_desc(py_descriptor_t pd)
{
    auto roi_pointer = reinterpret_cast<HailoROI *>(pd);
    return roi_pointer->shared_from_this();
}

#ifndef __MODULE_GEN_MACRO
#define __MODULE_GEN_MACRO PYBIND11_MODULE
#endif

class __HailoObjectGlue : public HailoObject, public std::enable_shared_from_this<__HailoObjectGlue>
{
public:
    using HailoObject::HailoObject;

    hailo_object_t get_type() override
    {
        PYBIND11_OVERRIDE_PURE(hailo_object_t, HailoObject, get_type);
    }
};

class __HailoMainObjectGlue : public HailoMainObject,
                              public std::enable_shared_from_this<__HailoMainObjectGlue>
{
public:
    using HailoMainObject::HailoMainObject;

    hailo_object_t get_type() override
    {
        PYBIND11_OVERRIDE_PURE(hailo_object_t, HailoMainObject, get_type);
    }
};

class __HailoROIGlue : public HailoROI, public std::enable_shared_from_this<__HailoROIGlue>
{
public:
    using HailoROI::HailoROI;

    hailo_object_t get_type() override { PYBIND11_OVERRIDE(hailo_object_t, HailoROI, get_type); }
};

class __HailoTileROIGlue : public HailoTileROI,
                           public std::enable_shared_from_this<__HailoTileROIGlue>
{
public:
    using HailoTileROI::HailoTileROI;

    hailo_object_t get_type() override { PYBIND11_OVERRIDE(hailo_object_t, HailoTileROI, get_type); }
};

class __NewHailoDetectionGlue : public NewHailoDetection,
                                public std::enable_shared_from_this<__NewHailoDetectionGlue>
{
public:
    using NewHailoDetection::NewHailoDetection;

    hailo_object_t get_type() override
    {
        PYBIND11_OVERRIDE(hailo_object_t, NewHailoDetection, get_type);
    }
};

class __HailoClassificationGlue : public HailoClassification,
                                  public std::enable_shared_from_this<__HailoClassificationGlue>
{
public:
    using HailoClassification::HailoClassification;

    hailo_object_t get_type() override
    {
        PYBIND11_OVERRIDE(hailo_object_t, HailoClassification, get_type);
    }
};

class __HailoLandmarksGlue : public HailoLandmarks,
                             public std::enable_shared_from_this<__HailoLandmarksGlue>
{
public:
    using HailoLandmarks::HailoLandmarks;

    hailo_object_t get_type() override
    {
        PYBIND11_OVERRIDE(hailo_object_t, HailoLandmarks, get_type);
    }
};

class __HailoMaskGlue : public HailoMask,
                             public std::enable_shared_from_this<__HailoMaskGlue>
{
public:
    using HailoMask::HailoMask;

    hailo_object_t get_type() override
    {
        PYBIND11_OVERRIDE_PURE(hailo_object_t, HailoMask, get_type);
    }
};

class __HailoDepthMaskGlue : public HailoDepthMask,
                             public std::enable_shared_from_this<__HailoDepthMaskGlue>
{
public:
    using HailoDepthMask::HailoDepthMask;

    hailo_object_t get_type() override
    {
        PYBIND11_OVERRIDE(hailo_object_t, HailoDepthMask, get_type);
    }
};

class __HailoClassMaskGlue : public HailoClassMask,
                             public std::enable_shared_from_this<__HailoClassMaskGlue>
{
public:
    using HailoClassMask::HailoClassMask;

    hailo_object_t get_type() override
    {
        PYBIND11_OVERRIDE(hailo_object_t, HailoClassMask, get_type);
    }
};

class __HailoConfClassMaskGlue : public HailoConfClassMask,
                                 public std::enable_shared_from_this<__HailoConfClassMaskGlue>
{
public:
    using HailoConfClassMask::HailoConfClassMask;

    hailo_object_t get_type() override
    {
        PYBIND11_OVERRIDE(hailo_object_t, HailoConfClassMask, get_type);
    }
};

class __HailoMatrixGlue : public HailoMatrix,
                          public std::enable_shared_from_this<__HailoMatrixGlue>
{
public:
    using HailoMatrix::HailoMatrix;

    hailo_object_t get_type() override
    {
        PYBIND11_OVERRIDE(hailo_object_t, HailoMatrix, get_type);
    }
};

class __HailoUniqueIDGlue : public HailoUniqueID,
                            public std::enable_shared_from_this<__HailoUniqueIDGlue>
{
public:
    using HailoUniqueID::HailoUniqueID;

    hailo_object_t get_type() override { PYBIND11_OVERRIDE(hailo_object_t, HailoUniqueID, get_type); }
};

__MODULE_GEN_MACRO(hailo, m)
{
    m.doc() = "HAILO postprocessing python extensions library";

    {
        py::enum_<hailo_object_t>(m, "hailo_object_t")
            .value("HAILO_ROI", HAILO_ROI)
            .value("HAILO_CLASSIFICATION", HAILO_CLASSIFICATION)
            .value("HAILO_DETECTION", HAILO_DETECTION)
            .value("HAILO_LANDMARKS", HAILO_LANDMARKS)
            .value("HAILO_TILE", HAILO_TILE)
            .value("HAILO_UNIQUE_ID", HAILO_UNIQUE_ID)
            .value("HAILO_MATRIX", HAILO_MATRIX)
            .value("HAILO_DEPTH_MASK", HAILO_DEPTH_MASK)
            .value("HAILO_CLASS_MASK", HAILO_CLASS_MASK)
            .value("HAILO_CONF_CLASS_MASK", HAILO_CONF_CLASS_MASK)
            .export_values();
    }

    {
        py::enum_<hailo_tiling_mode_t>(m, "hailo_tiling_mode_t")
            .value("SINGLE_SCALE", SINGLE_SCALE)
            .value("MULTI_SCALE", MULTI_SCALE)
            .export_values();
    }

    m.def("add_classification", &hailo_common::add_classification, "Add classification", "roi"_a,
          "type"_a, "label"_a, "confidence"_a, "class_id"_a = NULL_CLASS_ID);

    m.def("add_detection", &hailo_common::add_detection, "Add detection", "roi"_a, "bbox"_a,
          "label"_a, "confidence"_a, "class_id"_a = NULL_CLASS_ID);

    m.def("add_detections", &hailo_common::add_detections, "Add detections", "roi"_a, "detections"_a);

    m.def("create_flattened_bbox", &hailo_common::create_flattened_bbox, "Create flattened BBOX",
          "bbox"_a, "parent_bbox"_a);

    m.def("flatten_hailo_roi", &hailo_common::flatten_hailo_roi, "Flatten HAILO ROI", "roi"_a,
          "parent_roi"_a, "filter_type"_a);

    m.def("get_hailo_detections", &hailo_common::get_hailo_detections, "Get HAILO detections",
          "roi"_a);

    m.def("get_hailo_tiles", &hailo_common::get_hailo_tiles, "Get HAILO tiles", "roi"_a);

    m.def("get_hailo_roi_instances", &hailo_common::get_hailo_roi_instances,
          "Get HAILO ROI instances", "roi"_a);

    {
        py::class_<HailoPoint, std::shared_ptr<HailoPoint>>(m, "HailoPoint")
            .def(py::init<float, float, float>(), py::arg("x"), py::arg("y"), py::arg("confidence"))
            .def("x", &HailoPoint::x, "X")
            .def("y", &HailoPoint::y, "Y")
            .def("confidence", &HailoPoint::confidence, "Confidence")
            .def("__repr__", [](const HailoPoint &obj)
                 { return "<hailo.HailoPoint"s + "(" + std::to_string(reinterpret_cast<unsigned long>(&obj)) +
                          ")" + ">"; });
    }

    {
        py::class_<HailoBBox, std::shared_ptr<HailoBBox>>(m, "HailoBBox")
            .def(py::init<float, float, float, float>(), py::arg("xmin"), py::arg("ymin"), py::arg("width"), py::arg("height"))
            .def("xmin", &HailoBBox::xmin, "Xmin")
            .def("ymin", &HailoBBox::ymin, "Ymin")
            .def("width", &HailoBBox::width, "Width")
            .def("height", &HailoBBox::height, "Height")
            .def("xmax", &HailoBBox::xmax, "Xmax")
            .def("ymax", &HailoBBox::ymax, "Ymax")
            .def("__repr__", [](const HailoBBox &obj)
                 { return "<hailo.HailoBBox"s + "(" + std::to_string(reinterpret_cast<unsigned long>(&obj)) +
                          ")" + ">"; });
    }

    {
        py::class_<HailoObject, __HailoObjectGlue, std::shared_ptr<HailoObject>>(m, "HailoObject")
            .def(py::init<>())
            .def("__repr__", [](const HailoObject &obj)
                 { return "<hailo.HailoObject"s + "(" + std::to_string(reinterpret_cast<unsigned long>(&obj)) +
                          ")" + ">"; });
    }

    {
        py::class_<HailoMainObject, HailoObject, __HailoMainObjectGlue,
                   std::shared_ptr<HailoMainObject>>(m, "HailoMainObject")
            .def(py::init<>())
            .def("add_object", &HailoMainObject::add_object, "Add object", "obj"_a)
            .def("add_tensor", &HailoMainObject::add_tensor, "Add tensor", "tensor"_a)
            .def("remove_object", py::overload_cast<HailoObjectPtr>(&HailoMainObject::remove_object),
                 "Remove object", "obj"_a)
            .def("remove_object", py::overload_cast<uint>(&HailoMainObject::remove_object),
                 "Remove object", "index"_a)
            .def("get_tensor", &HailoMainObject::get_tensor, "Get tensor", "name"_a)
            .def("has_tensors", &HailoMainObject::has_tensors, "Has tensors")
            .def("get_tensors", &HailoMainObject::get_tensors, "Get tensors")
            .def("clear_tensors", &HailoMainObject::clear_tensors, "Clear tensors")
            .def("get_objects", &HailoMainObject::get_objects, "Get objects")
            .def("get_objects_typed", &HailoMainObject::get_objects_typed, "Get objects typed", "type"_a)
            .def("__repr__", [](const HailoMainObject &obj)
                 { return "<hailo.HailoMainObject"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<HailoROI, HailoMainObject, __HailoROIGlue, std::shared_ptr<HailoROI>>(m, "HailoROI")
            .def(py::init<HailoBBox>(), py::arg("bbox"))
            .def("get_type", &HailoROI::get_type, "Get type")
            .def("get_bbox", &HailoROI::get_bbox, "Get BBOX")
            .def("set_bbox", &HailoROI::set_bbox, "Set BBOX", "bbox"_a)
            .def("__repr__", [](const HailoROI &obj)
                 { return "<hailo.HailoROI"s + "(" + std::to_string(reinterpret_cast<unsigned long>(&obj)) +
                          ")" + ">"; });
    }

    {
        py::class_<HailoTileROI, HailoROI, __HailoTileROIGlue, std::shared_ptr<HailoTileROI>>(
            m, "HailoTileROI")
            .def(py::init<HailoBBox, uint, float, float, uint, hailo_tiling_mode_t>(), py::arg("bbox"), py::arg("index"), py::arg("overlap_x_axis"), py::arg("overlap_y_axis"), py::arg("layer"), py::arg("mode"))
            .def("get_type", &HailoTileROI::get_type, "Get type")
            .def("overlap_x_axis", &HailoTileROI::get_overlap_x_axis, "Overlap X axis")
            .def("overlap_y_axis", &HailoTileROI::get_overlap_y_axis, "Overlap Y axis")
            .def("index", &HailoTileROI::get_index, "Index")
            .def("layer", &HailoTileROI::get_layer, "Layer")
            .def("mode", &HailoTileROI::get_mode, "Mode")
            .def("__repr__", [](const HailoTileROI &obj)
                 { return "<hailo.HailoTileROI"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<NewHailoDetection, HailoROI, __NewHailoDetectionGlue,
                   std::shared_ptr<NewHailoDetection>>(m, "NewHailoDetection")
            .def(py::init<HailoBBox, const std::string &, float>(), py::arg("bbox"), py::arg("label"), py::arg("confidence"))
            .def(py::init<HailoBBox, int, const std::string &, float>(), py::arg("bbox"), py::arg("index"), py::arg("label"), py::arg("confidence"))
            .def(py::self < py::self)
            .def(py::self > py::self)
            .def("get_type", &NewHailoDetection::get_type, "Get type")
            .def("get_confidence", &NewHailoDetection::get_confidence, "Get confidence")
            .def("get_label", &NewHailoDetection::get_label, "Get label")
            .def("get_class_id", &NewHailoDetection::get_class_id, "Get class")
            .def("__repr__", [](const NewHailoDetection &obj)
                 { return "<hailo.NewHailoDetection"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<HailoClassification, HailoObject, __HailoClassificationGlue,
                   std::shared_ptr<HailoClassification>>(m, "HailoClassification")
            .def(py::init<const std::string &, const std::string &, float>(), py::arg("type"), py::arg("label"), py::arg("confidence"))
            .def(py::init<const std::string &, int, const std::string &, float>(), py::arg("type"), py::arg("index"), py::arg("label"), py::arg("confidence"))
            .def("get_type", &HailoClassification::get_type, "Get type")
            .def("get_confidence", &HailoClassification::get_confidence, "Get confidence")
            .def("get_label", &HailoClassification::get_label, "Get label")
            .def("get_classification_type", &HailoClassification::get_classification_type,
                 "Get classification type")
            .def("get_class_id", &HailoClassification::get_class_id, "Get class")
            .def("__repr__", [](const HailoClassification &obj)
                 { return "<hailo.HailoClassification"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<HailoLandmarks, HailoObject, __HailoLandmarksGlue, std::shared_ptr<HailoLandmarks>>(
            m, "HailoLandmarks")
            .def(py::init<std::string, float>(), py::arg("type"), py::arg("threshold"))
            .def(py::init<std::string, std::vector<HailoPoint>, float>(), py::arg("type"), py::arg("points"), py::arg("threshold"))
            .def("get_type", &HailoLandmarks::get_type, "Get type")
            .def("add_point", &HailoLandmarks::add_point, "Add point", "point"_a)
            .def("get_points", &HailoLandmarks::get_points, "Get points")
            .def("get_threshold", &HailoLandmarks::get_threshold, "Get threshold")
            .def("get_landmarks_type", &HailoLandmarks::get_landmarks_type, "Get landmarks type")
            .def("__repr__", [](const HailoLandmarks &obj)
                 { return "<hailo.HailoLandmarks"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<HailoMask, HailoObject, __HailoMaskGlue, std::shared_ptr<HailoMask>>(
            m, "HailoMask")
            .def(py::init<int, int, float>(), py::arg("mask_width"), py::arg("mask_height"), py::arg("transparency"))
            .def("get_width", &HailoMask::get_width, "Get width")
            .def("get_height", &HailoMask::get_height, "Get height")
            .def("__repr__", [](const HailoMask &obj)
                 { return "<hailo.HailoMask"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<HailoDepthMask, HailoMask, __HailoDepthMaskGlue, std::shared_ptr<HailoDepthMask>>(
            m, "HailoDepthMask", py::buffer_protocol())
            .def(py::init<std::vector<float>, int, int, float>(), py::arg("data_vec"), py::arg("mask_width"), py::arg("mask_height"), py::arg("transparency"))
            .def_buffer([](HailoDepthMask &obj) -> py::buffer_info
                        { return py::buffer_info(
                              const_cast<float * > (obj.get_data().data()),
                              sizeof(float),
                              py::format_descriptor<float>::format(),
                              2,
                              {obj.get_height(), obj.get_width()},
                              {sizeof(float) * obj.get_width(),
                               sizeof(float)}); })
            .def("get_type", &HailoDepthMask::get_type, "Get type")
            .def("get_data", &HailoDepthMask::get_data, "Get data")
            .def("__repr__", [](const HailoDepthMask &obj)
                 { return "<hailo.HailoDepthMask"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<HailoClassMask, HailoMask, __HailoClassMaskGlue, std::shared_ptr<HailoClassMask>>(
            m, "HailoClassMask", py::buffer_protocol())
            .def(py::init<std::vector<uint8_t>, int, int, float>(), py::arg("data_vec"), py::arg("mask_width"), py::arg("mask_height"), py::arg("transparency"))
            .def_buffer([](HailoClassMask &obj) -> py::buffer_info
                        { return py::buffer_info(
                              const_cast<uint8_t * > (obj.get_data().data()),
                              sizeof(uint8_t),
                              py::format_descriptor<uint8_t>::format(),
                              2,
                              {obj.get_height(), obj.get_width()},
                              {sizeof(uint8_t) * obj.get_width(),
                               sizeof(uint8_t)}); })
            .def("get_type", &HailoClassMask::get_type, "Get type")
            .def("get_data", &HailoClassMask::get_data, "Get data")
            .def("__repr__", [](const HailoClassMask &obj)
                 { return "<hailo.HailoClassMask"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<HailoConfClassMask, HailoMask, __HailoConfClassMaskGlue, std::shared_ptr<HailoConfClassMask>>(
            m, "HailoConfClassMask", py::buffer_protocol())
            .def(py::init<std::vector<float>, int, int, float, int>(), py::arg("data_vec"), py::arg("mask_width"), py::arg("mask_height"), py::arg("transparency"), py::arg("class_id"))
            .def_buffer([](HailoConfClassMask &obj) -> py::buffer_info
                        { return py::buffer_info(
                              const_cast<float * > (obj.get_data().data()),
                              sizeof(float),
                              py::format_descriptor<float>::format(),
                              2,
                              {obj.get_height(), obj.get_width()},
                              {sizeof(float) * obj.get_width(),
                               sizeof(float)}); })
            .def("get_type", &HailoConfClassMask::get_type, "Get type")
            .def("get_data", &HailoConfClassMask::get_data, "Get data")
            .def("__repr__", [](const HailoConfClassMask &obj)
                 { return "<hailo.HailoConfClassMask"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<HailoMatrix, HailoObject, __HailoMatrixGlue, std::shared_ptr<HailoMatrix>>(
            m, "HailoMatrix", py::buffer_protocol())
            .def(py::init<float *, uint32_t, uint32_t, uint32_t>(), py::arg("data_ptr"), py::arg("mat_height"), py::arg("mat_width"), py::arg("mat_features"))
            .def_buffer([](HailoMatrix &obj) -> py::buffer_info
                        { return py::buffer_info(
                              obj.get_data_ptr(),
                              sizeof(float),
                              py::format_descriptor<float>::format(),
                              3,
                              {obj.height(), obj.width(), obj.features()},
                              {sizeof(float) * obj.features() * obj.width(),
                               sizeof(float) * obj.features(), sizeof(float)}); })
            .def("width", &HailoMatrix::width, "Get width")
            .def("height", &HailoMatrix::height, "Get height")
            .def("features", &HailoMatrix::features, "Get number of features")
            .def("size", &HailoMatrix::size, "Get size")
            .def("shape", &HailoMatrix::shape, "Get shape")
            .def("get_data_ptr", &HailoMatrix::get_data_ptr, "Get shape")
            .def("__repr__", [](const HailoMatrix &obj)
                 { return "<hailo.HailoMatrix"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<HailoUniqueID, HailoObject, __HailoUniqueIDGlue, std::shared_ptr<HailoUniqueID>>(
            m, "HailoUniqueID")
            .def(py::init<>())
            .def(py::init<int>(), py::arg("id"))
            .def("get_id", &HailoUniqueID::get_id, "Get")
            .def("get_type", &HailoUniqueID::get_type, "Get type")
            .def("__repr__", [](const HailoUniqueID &obj)
                 { return "<hailo.HailoUniqueID"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }

    {
        py::class_<NewHailoTensor, std::shared_ptr<NewHailoTensor>>(m, "NewHailoTensor",
                                                                    py::buffer_protocol())
            .def(py::init<uint8_t *, const hailo_vstream_info_t &>(), py::arg("data"), py::arg("vstream_info"))
            .def_buffer([](NewHailoTensor &obj) -> py::buffer_info
                        { return py::buffer_info(obj.data(), sizeof(uint8_t),
                                                 py::format_descriptor<uint8_t>::format(), 3,
                                                 {obj.height(), obj.width(), obj.features()},
                                                 {sizeof(uint8_t) * obj.features() * obj.width(), sizeof(uint8_t) * obj.features(), sizeof(uint8_t)}); })
            .def("name", &NewHailoTensor::name, "Name")
            .def("vstream_info", &NewHailoTensor::vstream_info, "Vstream info")
            .def("data", &NewHailoTensor::data, "Data", py::return_value_policy::reference_internal)
            .def("width", &NewHailoTensor::width, "Width")
            .def("height", &NewHailoTensor::height, "Height")
            .def("features", &NewHailoTensor::features, "Features")
            .def("size", &NewHailoTensor::size, "Size")
            .def("shape", &NewHailoTensor::shape, "Shape")
            .def("fix_scale", &NewHailoTensor::fix_scale, "Fix scale", "num"_a)
            .def("get", &NewHailoTensor::get, "Get", "row"_a, "col"_a, "channel"_a)
            .def("get_full_percision", &NewHailoTensor::get_full_percision, "Get full percision", "row"_a,
                 "col"_a, "channel"_a)
            .def("__repr__", [](const NewHailoTensor &obj)
                 { return "<hailo.NewHailoTensor"s + "(" +
                          std::to_string(reinterpret_cast<unsigned long>(&obj)) + ")" + ">"; });
    }
    m.def("access_HailoMainObject_from_desc", &access_HailoMainObject_from_desc,
          "Access HailoMainObject from low-level py descriptor");
    m.def("access_HailoROI_from_desc", &access_HailoROI_from_desc,
          "Access HailoROI from low-level py descriptor");
}