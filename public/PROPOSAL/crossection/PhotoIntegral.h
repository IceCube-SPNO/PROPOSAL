#pragma once


#include "PROPOSAL/crossection/CrossSectionIntegral.h"

namespace PROPOSAL
{

class PhotoIntegral: public CrossSectionIntegral
{
    public:
        PhotoIntegral(const Parametrization&);
        PhotoIntegral(const PhotoIntegral&);
        virtual ~PhotoIntegral();

        CrossSection* clone() const { return new PhotoIntegral(*this); }

        // ----------------------------------------------------------------- //
        // Public methods
        // ----------------------------------------------------------------- //

        double CalculatedEdx(double energy);
};

} /* PROPOSAL */