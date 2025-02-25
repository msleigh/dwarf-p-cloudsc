! (C) Copyright 1988- ECMWF.
!
! This software is licensed under the terms of the Apache Licence Version 2.0
! which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
!
! In applying this licence, ECMWF does not waive the privileges and immunities
! granted to it by virtue of its status as an intergovernmental organisation
! nor does it submit to any jurisdiction.

MODULE FCCLD_MOD
  !*
  !     ------------------------------------------------------------------
  !     This COMDECK defines functions to be used in the cloud scheme
  !       other than the standard saturation vapour pressure
  !
  !       FKOOP modifies the ice saturation mixing ratio for homogeneous 
  !       nucleation
  !
  !     note: PTARE is temperature and is definited in frttre.h 
  !           which MUST be included before this function block
  !
  !     **********************************************
  !     KOOP formula for homogeneous nucleation of ice 
  !     **********************************************
  !
  !               INPUT : PTARE = TEMPERATURE 
  USE PARKIND1,   ONLY : JPIM, JPRB
  USE YOETHF,     ONLY : RKOOP1, RKOOP2
  USE FCTTRE_MOD, ONLY : FOEELIQ, FOEEICE

  IMPLICIT NONE
  CONTAINS

  PURE ELEMENTAL FUNCTION FOKOOP(PTARE)
    REAL(KIND=JPRB) :: FOKOOP
    REAL(KIND=JPRB), VALUE :: PTARE
    !$acc routine seq

    FOKOOP = MIN(RKOOP1-RKOOP2*PTARE,FOEELIQ(PTARE)/FOEEICE(PTARE))
  END FUNCTION FOKOOP

END MODULE FCCLD_MOD
