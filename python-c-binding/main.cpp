#include <pybind11/pybind11.h>

#include "lite/nlp_engine.h"
#include "lite/vtrun.h"

namespace py = pybind11;

PYBIND11_MODULE(nlppp, m) {
    py::class_<NLP_ENGINE>(m, "NLP_ENGINE")
        .def(py::init<std::string>())
        .def("analyze", [](NLP_ENGINE &self, const std::string &analyzer,const std::string& input, bool develop=false, bool silent=false, bool compiled=false){
            std::istringstream iss(input);
            std::ostringstream oss;
            self.analyze(const_cast<char *>(analyzer.c_str()), &iss, &oss, develop, silent, compiled);
            return oss.str();
        }, py::arg("self") ,py::arg("analyzer"), py::arg("develop") = false, py::arg("silent") = false, py::arg("compiled") = false);
}