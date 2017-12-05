#define BENCHPRESS_CONFIG_MAIN
#include "benchpress.hpp"

#include "tvector.h"
#include <vector>
#include <list>

/*
void appendSmallBenchmark(benchpress::context* ctx)
{
	for (int i = 0; i < ctx->num_iterations(); ++i)
	{
		tVector<int> v;
		for (int j = 0; j < 10; ++j)
		{
			v.append(j);
		}
	}
}


void appendMediumBenchmark(benchpress::context* ctx)
{
	for (int i = 0; i < ctx->num_iterations(); ++i)
	{
		tVector<int> v;
		for (int j = 0; j < 10000; ++j)
		{
			v.append(j);
		}
	}
}

*/
void appendLargeBenchmark(benchpress::context* ctx)
{
	for (int i = 0; i < ctx->num_iterations(); ++i)
	{
		std::vector<int> v;
		for (int j = 0; j < 63999; ++j)
		{
			v.push_back(j);
		}
	}
}


void accessLargeBenchmark(benchpress::context* ctx)
{
	std::vector<int> v;
	for (int j = 0; j < 63999; ++j)
	{
		v.push_back(j);
	}

	ctx->reset_timer();

	for (int i = 0; i < ctx->num_iterations(); ++i)
	{
		int sum = 0;
		for (int j = 0; j < 63999; ++j)
		{
			sum += v.at(j);
		}
		benchpress::escape(&sum);
	}
}

void eraseLargeBenchmark(benchpress::context* ctx)
{

	for (int i = 0; i < ctx->num_iterations(); ++i)
	{
		ctx->stop_timer();
		std::vector<int> v;
		for (int j = 0; j < 63999; ++j)
		{
			v.push_back(j);
		}
		ctx->start_timer();

		for (int j = 0; j < 1000; ++j)
		{
			v.erase(std::begin(v));
		}
	}
}



void appendListBenchmark(benchpress::context* ctx)
{
	for (int i = 0; i < ctx->num_iterations(); ++i)
	{
		tVector<int> v;
		for (int j = 0; j < 63999; ++j)
		{
			v.append(j);
		}
	}
}

void accessListLargeBenchmark(benchpress::context* ctx)
{
	tVector<int> v;
	for (int j = 0; j < 63999; ++j)
	{
		v.append(j);
	}

	ctx->reset_timer();

	for (int i = 0; i < ctx->num_iterations(); ++i)
	{
		int sum = 0;
		for (int j = 0;j < v.getSize();j++)
		{
			sum += v[j];
		}
		benchpress::escape(&sum);
	}
}

void eraseListLargeBenchmark(benchpress::context* ctx)
{
	
	for (int i = 0; i < ctx->num_iterations(); ++i)
	{
		ctx->stop_timer();
		tVector<int >v;
		for (int j = 0; j < 63999; ++j)
		{
			v.append(j);
		}
		ctx->start_timer();

		for (int j = 0; j < 1000; ++j)
		{
			v.erase(0);
		}
	}
}

//BENCHMARK("Append - small", appendSmallBenchmark);
//BENCHMARK("Append - medium", appendMediumBenchmark); 

BENCHMARK("Append - large", appendLargeBenchmark);
BENCHMARK("Access - large", accessLargeBenchmark);
BENCHMARK("Erase - large", eraseLargeBenchmark);
BENCHMARK("List Append - large", appendListBenchmark);
BENCHMARK("List Access - large", accessListLargeBenchmark);

BENCHMARK("List Erase - large", eraseListLargeBenchmark);