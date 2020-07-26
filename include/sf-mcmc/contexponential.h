#pragma once

#include <cmath>
#include <sf-mcmc/schedule.h>
#include <sf-mcmc/schedule.h>
#include <sf-mcmc/common.h>

/**
 * \brief Continous exponential Schedule used for MCMC simulated annealing.
 */
class ContinuousExponentialSchedule : public Schedule {
    public:
        /**
         * \brief Constructs a continuous exponential schedule.
         *
         * \param iterationCount 
         *  The number of iterations durich which the schedule will be ran.
         *
         * \param offset 
         *  The offset value of the exponential function (initial temperature).
         *
         * \param base 
         *  The base of the exponential term.
         */
        ContinuousExponentialSchedule(int iterationCount, Float offset, Float base) :
            Schedule(), m_currentTime(0), m_stepSize(1.0 / iterationCount),
            m_offset(offset), m_base(base) { } 

        /**
         * \brief Pybind bindings for ContinuousExponentialSchedule. 
         */
        static void defPybind(pybind11::module &m) {
            pybind11::class_<ContinuousExponentialSchedule, Schedule>(m, "continuousExponentialSchedule")
                .def(pybind11::init<int, Float, Float>(),
                        pybind11::arg("iterationCount"),
                        pybind11::arg("offset"),
                        pybind11::arg("base"));
        }

        /**
         * \brief Computes and returns the next value of the temperature.
         */
        inline Float computeNextTemp() {
            float result = m_offset * std::pow(m_base,  -m_currentTime);
            m_currentTime += m_stepSize;
            return result;
        }

    private:
        Float m_stepSize;
        Float m_currentTime;
        Float m_offset;
        Float m_base;
};

