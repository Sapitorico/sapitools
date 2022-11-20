#include "network.h"
/**
 */
int main()
{
	int layerSizes[] = {2, 3, 1};
	neuralNet *nn = newNeuralNet(3, layerSizes);
	double inputs[] = {1.0, 2.0};
	propagate(nn, inputs);
	double outputs[1];
	getOutputs(nn, outputs);

	printf("Output: %f\n", outputs[0]);
	freeNeuralNet(nn);
	return 0;
}
