#include "network.h"
/**
 */
void getOutputs(neuralNet *nn, double *outputs)
{
	int i = 0;
	layer *outputLayer = NULL;

	outputLayer = &nn->layers[nn->numLayers - 1];
	for (; i < outputLayer->numNeurons; i++)
		outputs[i] = outputLayer->neurons[i].value;
}
