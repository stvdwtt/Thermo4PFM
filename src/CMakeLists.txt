set(SOURCES ${CMAKE_SOURCE_DIR}/src/InterpolationType.cc
            ${CMAKE_SOURCE_DIR}/src/Determinant.cc
            ${CMAKE_SOURCE_DIR}/src/NewtonSolver.cc
            ${CMAKE_SOURCE_DIR}/src/xlogx.cc
            ${CMAKE_SOURCE_DIR}/src/functions.cc
            ${CMAKE_SOURCE_DIR}/src/well_functions.cc
            ${CMAKE_SOURCE_DIR}/src/InterpolationType.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADFunctions.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADSpeciesPhaseGibbsEnergy.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADSpeciesPhaseGibbsEnergyExpansion.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADFreeEnergyFunctionsBinary.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADFreeEnergyFunctionsBinaryThreePhase.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADFreeEnergyFunctionsBinary3Ph2Sl.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADFreeEnergyFunctionsTernary.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADConcSolverBinary.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADConcSolverBinaryThreePhase.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADConcSolverBinary3Ph2Sl.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADConcSolverTernary.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADEqConcSolverBinary.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADEqConcSolverTernary.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADConcSolverTernary.cc
            ${CMAKE_SOURCE_DIR}/src/CALPHADTieLineConcSolverTernary.cc
            ${CMAKE_SOURCE_DIR}/src/KKSdiluteBinaryConcSolver.cc
            ${CMAKE_SOURCE_DIR}/src/KKSFreeEnergyFunctionDiluteBinary.cc
            ${CMAKE_SOURCE_DIR}/src/xlogx.cc)

if(${SHARED_LIB})
  add_library(thermo4pfm SHARED ${SOURCES})
else()
  add_library(thermo4pfm ${SOURCES})
endif()

set(PUBLIC_HEADERS
    PhysicalConstants.h
    KKSFreeEnergyFunctionDiluteBinary.h
    InterpolationType.h
    Determinant.h
    Phases.h
    NewtonSolver.h
    xlogx.h
    functions.h
    well_functions.h
    datatypes.h
    CALPHADFunctions.h
    CALPHADSpeciesPhaseGibbsEnergy.h
    CALPHADSpeciesPhaseGibbsEnergyExpansion.h
    CALPHADFreeEnergyFunctionsBinary.h
    CALPHADFreeEnergyFunctionsBinaryThreePhase.h
    CALPHADFreeEnergyFunctionsBinary3Ph2Sl.h
    CALPHADFreeEnergyFunctionsTernary.h
    CALPHADConcSolverBinary.h
    CALPHADConcSolverBinaryThreePhase.h
    CALPHADConcSolverBinary3Ph2Sl.h
    CALPHADConcSolverTernary.h
    CALPHADEqConcSolverBinary.h
    CALPHADEqConcSolverTernary.h
    CALPHADTieLineConcSolverTernary.h
    KKSdiluteBinaryConcSolver.h
   )
set(THERMODATA
    ${CMAKE_SOURCE_DIR}/thermodynamic_data/calphadAlCuLFccTheta.json
    ${CMAKE_SOURCE_DIR}/thermodynamic_data/calphadAuNi.json
    ${CMAKE_SOURCE_DIR}/thermodynamic_data/calphadMoNbTa.json
    )

install(FILES ${PUBLIC_HEADERS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
install(TARGETS thermo4pfm
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${THERMODATA}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/thermodynamic_data)
