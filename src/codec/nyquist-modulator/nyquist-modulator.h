/**
* @file ofdmfft.h
* @author Kamil Rog
*
* 
*/
#ifndef NYQUIST_MODULATOR_H
#define NYQUIST_MODULATOR_H

#include <string>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <fftw3.h>

#include "common.h"

/**
 * @brief Digital nyquist quadrature modulator & demodulaor class
 * which upsamples/downsamples the signal at a factor of 2
 * The modulation esentially inteleaves the inphase and 
 * quadrature signals in the folllwing fashion:
 * 
 * +Real(c(n)), +Imag(c(n)), -Real(c(n+1), -Imag(c(n+1))
 * 
 * The demodulator is the inverse of this process and combines
 * the real and imaginary pairs back to form IFFT output.
 * 
 */
class NyquistModulator {

public:


	/**
	* Constructor runs setup function and sets the setup flag.
	* 
	* @param OFDMSettings
	*
	*/
	NyquistModulator(OFDMSettings &settings);


	/**
	* Destructor 
	* Runs close function.
	*
	*/
	~NyquistModulator();


	void Modulate(double *ifftOutput);
	void Demodulate(double *rxBuffer, fftw_complex *pFFTInput, const size_t symbolStart);


private:

	OFDMSettings &m_ofdmSettings;
	size_t m_RingBufferBoundary;
	double *m_TempBuffer;

};

#endif
