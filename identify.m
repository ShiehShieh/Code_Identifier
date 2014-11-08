clear ; close all; clc

load('weights.mat');

data = load('new_file.txt');
x = data(1:end - 1);
y = data(end);

local = zeros(1, size(Theta2, 1));

local(y) = 1;

% y = local;

h1 = sigmoid(Theta1 * [1; x']);
h2 = sigmoid(Theta2 * [1; h1]);
[dummy, p] = max(h2);

dummy
p
y

