#include "network.h"
double exp(double x);
/**
 */
void propagate(neuralNet *nn, double *inputs)
{
	int i = 0;
	int j = 0;
	int k = 0;
	layer *l = NULL;
	neuron *n = NULL;

	for (; i < nn->numLayers; i++)
		l = &nn->layers[i];
	for (; j < l->numNeurons; j++)
		n = &l->neurons[j];
	n->value = 0;
	if (i == 0)
		n->value = inputs[j];
	else
	{
		for (; k < nn->layers[i - 1].numNeurons; k++)
			n->value += n->weights[k] * nn->layers[i - 1].neurons[k].value;
	}
	n->value = 1.0 / (1.0 + exp(-n->value));
}
double exp(double x)
{
	double y = 1.0;
	double y2 = 1.0;
	double z = 1.0;
	int n = 1;

	while (z > 1e-6)
	{
		y *= x / n++;
		y2 += y;
		z = y / y2;
	}
	return (y2);
}
