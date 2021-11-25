! (C) Copyright 1988- ECMWF.
!
! This software is licensed under the terms of the Apache Licence Version 2.0
! which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
!
! In applying this licence, ECMWF does not waive the privileges and immunities
! granted to it by virtue of its status as an intergovernmental organisation
! nor does it submit to any jurisdiction.

INTERFACE
SUBROUTINE CLOUDSC&
 & (KIDIA, KFDIA, KLON, KLEV,&
 & PTSPHY,&
 & PT, PQ, tendency_cml,tendency_tmp,tendency_loc,&
 & PVFA, PVFL, PVFI, PDYNA, PDYNL, PDYNI,&
 & PHRSW, PHRLW,&
 & PVERVEL, PAP, PAPH,&
 & PLSM, LDCUM, KTYPE,&
 & PLU, PLUDE, PSNDE, PMFU, PMFD,&
 & LDSLPHY, LDMAINCALL,&
 & PA,&
 & PCLV,&
 & PSUPSAT,&
 & PLCRIT_AER,PICRIT_AER,&
 & PRE_ICE,&
 & PCCN, PNICE,&
 & PCOVPTOT, PRAINFRAC_TOPRFZ,&
 & PFSQLF, PFSQIF , PFCQNNG, PFCQLNG,&
 & PFSQRF, PFSQSF , PFCQRNG, PFCQSNG,&
 & PFSQLTUR, PFSQITUR ,&
 & PFPLSL, PFPLSN, PFHPSL, PFHPSN,&
 & PEXTRA, KFLDX) 
USE PARKIND1 , ONLY : JPIM, JPRB
USE YOECLDP , ONLY : YRECLDP, NCLDQV, NCLDQL, NCLDQR, NCLDQI, NCLDQS, NCLV
USE YOMPHYDER ,ONLY : STATE_TYPE
REAL(KIND=JPRB) ,INTENT(IN) :: PLCRIT_AER(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PICRIT_AER(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PRE_ICE(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PCCN(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PNICE(KLON,KLEV)
INTEGER(KIND=JPIM),INTENT(IN) :: KLON
INTEGER(KIND=JPIM),INTENT(IN) :: KLEV
INTEGER(KIND=JPIM),INTENT(IN) :: KIDIA
INTEGER(KIND=JPIM),INTENT(IN) :: KFDIA
REAL(KIND=JPRB) ,INTENT(IN) :: PTSPHY
REAL(KIND=JPRB) ,INTENT(IN) :: PT(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PQ(KLON,KLEV)
TYPE (STATE_TYPE) , INTENT (IN) :: tendency_cml
TYPE (STATE_TYPE) , INTENT (IN) :: tendency_tmp
TYPE (STATE_TYPE) , INTENT (OUT) :: tendency_loc
REAL(KIND=JPRB) ,INTENT(IN) :: PVFA(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PVFL(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PVFI(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PDYNA(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PDYNL(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PDYNI(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PHRSW(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PHRLW(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PVERVEL(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PAP(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PAPH(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(IN) :: PLSM(KLON)
LOGICAL ,INTENT(IN) :: LDCUM(KLON)
INTEGER(KIND=JPIM),INTENT(IN) :: KTYPE(KLON)
REAL(KIND=JPRB) ,INTENT(IN) :: PLU(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(INOUT) :: PLUDE(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PSNDE(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PMFU(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(IN) :: PMFD(KLON,KLEV)
LOGICAL ,INTENT(IN) :: LDSLPHY
LOGICAL ,INTENT(IN) :: LDMAINCALL
REAL(KIND=JPRB) ,INTENT(IN) :: PA(KLON,KLEV)
INTEGER(KIND=JPIM),INTENT(IN) :: KFLDX
REAL(KIND=JPRB) ,INTENT(INOUT) :: PEXTRA(KLON,KLEV,KFLDX)
REAL(KIND=JPRB) ,INTENT(IN) :: PCLV(KLON,KLEV,NCLV)
REAL(KIND=JPRB) ,INTENT(IN) :: PSUPSAT(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(OUT) :: PCOVPTOT(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(OUT) :: PRAINFRAC_TOPRFZ(KLON)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFSQLF(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFSQIF(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFCQLNG(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFCQNNG(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFSQRF(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFSQSF(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFCQRNG(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFCQSNG(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFSQLTUR(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFSQITUR(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFPLSL(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFPLSN(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFHPSL(KLON,KLEV+1)
REAL(KIND=JPRB) ,INTENT(OUT) :: PFHPSN(KLON,KLEV+1)
END SUBROUTINE CLOUDSC
END INTERFACE
