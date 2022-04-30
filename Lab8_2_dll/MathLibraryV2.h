#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" MATHLIBRARY_API double CalcAverageHarmonic(double a, double b, double c);
extern "C" MATHLIBRARY_API double CalcTaylorRow(double x, int n);
extern "C" MATHLIBRARY_API double CalcPolygonArea(double a, int n);
