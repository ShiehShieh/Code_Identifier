clear ; close all; clc

load('weights.mat')
data = load('test.txt');

testX = data(:, 1:end - 1);
testy = data(:, end);

% m = size(y, 1);

% h1 = sigmoid(Theta1 * [ones(m, 1) x]');
% h2 = sigmoid(Theta2 * [ones(size(h1, 2), 1) h1']');
% [dummy, p] = max(h2', [], 2);

% dummy
% p
% y

nn_params = [Theta1(:); Theta2(:)];

nnCostFunction(nn_params, size(testX, 2), 50, 4, testX, testy, 1)

pred = predict(Theta1, Theta2, testX);

fprintf('\nTesting Set Accuracy: %f\n', mean(double(pred == testy)) * 100);

