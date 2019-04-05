/*
 * Random.h
 *
 *  Created on: Apr 4, 2019
 *      Author: javiervega
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <memory>

#pragma once

class I_Random
{
public:
	virtual ~I_Random() {}
	virtual int GenerateRandom(int start, int end) = 0;
};

std::unique_ptr<I_Random> MakeRandom();

#endif /* RANDOM_H_ */
