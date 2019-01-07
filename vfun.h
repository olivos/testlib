/*
 * vfun.h
 *
 *  Created on: Jul 27, 2018
 *      Author: oliv
 *
 *      Represents f : E -> F.
 *      It inheritates from the vecSpace E, F can be obtained with the outputSpace method.
 *      Contrary to fun, the result is represented by an armadillo matrix (matrix is a vec if dim(E)=1 ).
 *
 *
 *      Declaration :  vfun(E,mat& M) : BEWARE if E.nx = n then M should be of size n+1 (indeed n is the number of steps so
 *      there are n+1 points in the space)
 *      (No default constructor because vec ref has to be initialized)
 *
 *      Note : not using a reference for the vecSpace is fine because it a vecSpace very light in terms of memory
 */

#ifndef VFUN_H_
#define VFUN_H_

#include "fonction.h"

namespace vSpace {

class vfun: public fonction {
public:
	vfun(const vecSpace& E,const arma::mat& M);
//	vfun();
	virtual ~vfun();
//	virtual arma::vec diff ();

	virtual double operator() (const double& x) const;
	virtual double operator() (const double& x,const double& y) const;


    friend std::ostream& operator<<(std::ostream& os, const vfun& E){
    	switch(E.dim){
    	case 1 : {

    		int nx = E.sizes(0);

    		os << "[";
    		for(int j = 0 ; j < nx ; j++){
    			os << E.operator()(E.X(j))<< ",";
    		}
			os << E.operator()(E.X(nx))<<  "]";return os;}
    	case 2 : {

    		int nx = E.sizes(0);
    		int ny = E.sizes(1);

    		os<< "[";
    		for(int i = 0 ; i < ny ; i++){

				os << "[";
				for(int j = 0 ; j < nx ; j++){
					os << E.operator()(E.Y(i),E.X(j))<< ",";
				}
				os << E.operator()(E.Y(i),E.X(nx))<<  "],"; }
			os << "[";

			for(int j = 0 ; j < nx ; j++){
				os << E.operator()(E.Y(ny),E.X(j))<< ",";
			}
			os << E.operator()(E.Y(ny),E.X(nx))<<  "]]"; return os;

    		}

    	}
    	return os;
    }

	const arma::mat& getM() const {
		return M;
	}

protected :
	const arma::mat& M;
};

} /* namespace vSpace */

#endif /* VFUN_H_ */




