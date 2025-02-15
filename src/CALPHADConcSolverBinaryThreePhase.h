#ifndef included_CALPHADConcSolverBinaryThreePhase
#define included_CALPHADConcSolverBinaryThreePhase

#include "NewtonSolver.h"
#include "datatypes.h"

namespace Thermo4PFM
{
class CALPHADConcSolverBinaryThreePhase
    : public NewtonSolver<3, CALPHADConcSolverBinaryThreePhase,
          JacobianDataType>
{
public:
#ifdef HAVE_OPENMP_OFFLOAD
#pragma omp declare target
#endif
    /// compute "internal" concentrations cL, cS1, cS2 by solving KKS
    /// equations
    /// conc: initial guess and final solution (concentration in each phase)
    int ComputeConcentration(double* const conc, const double tol,
        const int max_iters, const double alpha = 1.)
    {
        return NewtonSolver::ComputeSolution(conc, tol, max_iters, alpha);
    }

    /// setup model paramater values to be used by solver,
    /// including composition "c0" and phase fraction "hphi"
    /// to solve for
    void setup(const double c0, const double hphi0, const double hphi1,
        const double hphi2, const double RTinv,
        const CalphadDataType* const Lmix_L_,
        const CalphadDataType* const Lmix_S0_,
        const CalphadDataType* const Lmix_S1_, const CalphadDataType* const fA,
        const CalphadDataType* const fB);

    /// evaluate RHS of the system of eqautions to solve for
    /// specific to this solver
    void RHS(const double* const x, double* const fvec);

    /// evaluate Jacobian of system of equations
    /// specific to this solver
    void Jacobian(const double* const x, JacobianDataType** const fjac);
#ifdef HAVE_OPENMP_OFFLOAD
#pragma omp end declare target
#endif

private:
    ///
    /// Nominal composition to solve for
    ///
    double c0_;

    ///
    /// phase fractions to solve for
    ///
    double hphi0_;
    double hphi1_;
    double hphi2_;

    double RTinv_;

    ///
    /// 4 L coefficients for 3 possible phases (L, S0, S1)
    ///
    CalphadDataType Lmix_L_[4];
    CalphadDataType Lmix_S0_[4];
    CalphadDataType Lmix_S1_[4];

    ///
    /// energies of 2 species, in three phases each
    ///
    CalphadDataType fA_[3];
    CalphadDataType fB_[3];

    // internal functions to help evaluate RHS and Jacobian
    void computeXi(const double* const c, double xi[3]) const;

    void computeDxiDc(const double* const c, double dxidc[3]) const;
};
}
#endif
