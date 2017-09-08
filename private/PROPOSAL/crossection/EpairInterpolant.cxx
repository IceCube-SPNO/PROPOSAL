
#include <boost/bind.hpp>

#include "PROPOSAL/crossection/EpairInterpolant.h"
#include "PROPOSAL/crossection/EpairIntegral.h"
#include "PROPOSAL/crossection/parametrization/Parametrization.h"

#include "PROPOSAL/math/InterpolantBuilder.h"

#include "PROPOSAL/methods.h"
#include "PROPOSAL/Constants.h"
#include "PROPOSAL/Output.h"

using namespace PROPOSAL;

EpairInterpolant::EpairInterpolant(Parametrization& param): CrossSectionInterpolant(param)
{
    Parametrization::Definition param_def = parametrization_.GetDefinition();
    Interpolant1DBuilder builder1d;
    Helper::InterpolantBuilderContainer builder_container;

    // Needed for CalculatedEdx integration
    EpairIntegral epair(param);

    builder1d.SetMax(NUM1)
        .SetXMin(param.GetParticleDef().low)
        .SetXMax(BIGENERGY)
        .SetRomberg(param_def.order_of_interpolation)
        .SetRational(true)
        .SetRelative(false)
        .SetIsLog(true)
        .SetRombergY(param_def.order_of_interpolation)
        .SetRationalY(false)
        .SetRelativeY(false)
        .SetLogSubst(true)
        .SetFunction1D(boost::bind(&CrossSection::CalculatedEdx, epair, _1));

    builder_container.push_back(std::make_pair(&builder1d, &dedx_interpolant_));

    log_info("Initialize dEdx for %s", typeid(parametrization_).name());
    Helper::InitializeInterpolation("dEdx",
                                    builder_container,
                                    std::vector<Parametrization*>(1, &parametrization_));
    log_info("Initialization dEdx for %s done!", typeid(parametrization_).name());
}

EpairInterpolant::EpairInterpolant(const EpairInterpolant& epair): CrossSectionInterpolant(epair)
{
}

EpairInterpolant::~EpairInterpolant()
{
}

// ----------------------------------------------------------------- //
// Public methods
// ----------------------------------------------------------------- //

// ------------------------------------------------------------------------- //
double EpairInterpolant::CalculatedEdx(double energy)
{
    if (parametrization_.GetMultiplier() <= 0)
    {
        return 0;
    }

    return std::max(dedx_interpolant_->Interpolate(energy), 0.0);
}