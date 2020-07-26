#include <iostream>
#include <pybind11/pybind11.h>
#include <Eigen/Dense>
#include <sf-mcmc/common.h>
#include <sf-mcmc/helpers.h>
#include <sf-mcmc/sampler.h>
#include <sf-mcmc/schedule.h>
#include <sf-mcmc/constant.h>
#include <sf-mcmc/contlinear.h>
#include <sf-mcmc/contpolynomial.h>
#include <sf-mcmc/contlogarithmic.h>
#include <sf-mcmc/contexponential.h>
#include <sf-mcmc/mcmc.h>
#include <sf-mcmc/competition.h>
#include <sf-mcmc/multimcmc.h>
#include <sf-mcmc/multicompetition.h>

namespace py = pybind11;

using namespace std;

/**
 * Calls all pybind definitions.
 */
PYBIND11_MODULE(sf-mcmc, m) {
    m.doc() = R"pbdoc(
        sf-mcmc pthon bindings
        -----------------------

        .. currentmodule:: mcmc

        .. autosummary::
           :toctree: _generate

    )pbdoc";

    defPybindHelpers(m);
    Sampler::defPybind(m);
    Schedule::defPybind(m);
    ConstantSchedule::defPybind(m);
    ContinuousLinearSchedule::defPybind(m);
    ContinuousPolynomialSchedule::defPybind(m);
    ContinuousLogarithmicSchedule::defPybind(m);
    ContinuousExponentialSchedule::defPybind(m);
    MCMCRunner::defPybind(m);
    CompetitionRunner::defPybind(m);
    MultiMCMCRunner::defPybind(m);
    MultiCompetitionRunner::defPybind(m);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
