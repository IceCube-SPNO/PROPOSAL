
#pragma once

#include "PROPOSAL/crossection/CrossSection.h"

namespace PROPOSAL
{

class CrossSectionIntegral: public CrossSection
{
    public:
        CrossSectionIntegral(Parametrization&);
        CrossSectionIntegral(const CrossSectionIntegral&);
        virtual ~CrossSectionIntegral();

        virtual CrossSection* clone() const = 0;

        virtual double CalculatedEdx(double energy) = 0;
        virtual double CalculatedNdx(double energy);
        virtual double CalculatedNdx(double energy, double rnd);
        double CalculateStochasticLoss(double energy, double rnd1, double rnd2);

        // Needed to initialize interpolation
        // double FunctionToBuildDEdxInterpolant(double energy);
        double FunctionToBuildDNdxInterpolant(double energy, int component);
        double FunctionToBuildDNdxInterpolant2D(double energy, double v, int component);

    protected:
        virtual double CalculateStochasticLoss(double energy, double rnd1);
};

} /* PROPOSAL */