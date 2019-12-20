#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .Call calls */
extern SEXP warp_warp_distance(SEXP, SEXP, SEXP, SEXP);
extern SEXP warp_warp_change(SEXP, SEXP, SEXP, SEXP);
extern SEXP warp_warp_boundary(SEXP, SEXP, SEXP, SEXP);
extern SEXP warp_class_type(SEXP);
extern SEXP warp_date_get_year(SEXP);
extern SEXP warp_date_get_year_month(SEXP);

// Defined below
SEXP warp_init_library(SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"warp_warp_distance",       (DL_FUNC) &warp_warp_distance, 4},
  {"warp_warp_change",         (DL_FUNC) &warp_warp_change, 4},
  {"warp_warp_boundary",       (DL_FUNC) &warp_warp_boundary, 4},
  {"warp_class_type",          (DL_FUNC) &warp_class_type, 1},
  {"warp_date_get_year",       (DL_FUNC) &warp_date_get_year, 1},
  {"warp_date_get_year_month", (DL_FUNC) &warp_date_get_year_month, 1},
  {"warp_init_library",        (DL_FUNC) &warp_init_library, 1},
  {NULL, NULL, 0}
};

void R_init_warp(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}

void warp_init_utils(SEXP ns);

SEXP warp_init_library(SEXP ns) {
  warp_init_utils(ns);
  return R_NilValue;
}
