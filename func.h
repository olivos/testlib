/*
 * func.h
 * STATIC CLASS containing several methods for function objects (such as fun and vfun)
 *
 *  Created on: Aug 2, 2018
 *      Author: oliv
 */

#ifndef FUNC_H_
#define FUNC_H_

#include "fun.h"
#include "vfun.h"
#include <queue>

namespace vSpace {

class func {
public:
//
//	static
//	double Ide (double x){
//		return x;
//	}
//
	static double max(const fonction & f); /* finds max value of f : realSpace -> realSpace  */

//	Computes a moving average using a queue, the queue has to be initalized with the right number
//	of values!
	static double mavg(const double & avg,const double& next, const int& n, std::queue<double> & q );

//	static double min( function & f); /* finds max value of f : realSpace -> realSpace */
//
//	static realSpace OutputSpace(function & f, int n = 0); /* returns the output set of f : realSpace -> realSpace
//	using min and max.
//	By default the output realSpace will have as many points as the input one */
//
//	static arma::vec arc( vfun & f, function & phi); /* Returns f(t,phi(t)) where f : T x X -> R and phi : T -> X */
//
//
//	static double diff( function & f, double x); /* differential in a single point */
//	static double diff( vfun & f, double x, double y,int i); /* differential in a single point for two dimensional input space,
//	 i = 1 differentiate along x axis, i = 2 along y axis */
//	static arma::vec diff( function & f);
	static double ide (const double & x){return x;}
	static double puiss2(const double & x){return pow(x,2);}
	static arma::vec prim(const fonction & f, double (&g) (const double&) = ide); /* primitive nulle en la borne inf segment de départ : le realSpace f.getX() */
//	static arma::vec prim( function & f,realSpace new_X); /* primitive nulle en le minimum du segment new_X : évite de redéfinir une nouvelle function avant d'appeler prim */
//
//	static arma::vec prim( function & f, double a); /* primitive nul in a  SLOWER than the previous method (calls V = prim(f), gets the value in a and then subtracts it to V)*/
//	static double integ( function & f, double a , double b); /* Value of integral between a and b */
//
////	computes discrete mean of a function of a realSpace, if g specified mean of g(f)
//	static double dMean(function& f , double(&g)(double) = Ide);
//


private:
	func();
	virtual ~func();
};

} /* namespace vSpace */

#endif /* FUNC_H_ */
