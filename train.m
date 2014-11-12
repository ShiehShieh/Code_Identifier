%% Initialization
clear ; close all; clc

% Load Training Data
fprintf('Loading and Visualizing Data ...\n')

data = load('data.txt');
X = data(:, 1:end-1);
y = data(:, end);

num_set = unique(y);

m = size(y, 1);
input_layer_size = size(X, 2);  % Depending on the dataset
hidden_layer_size = 50;         % 25 hidden units
num_labels = size(num_set, 1);  % Depending on the dataset
                                % (note that we have mapped "0" to label 10)


fprintf('\nInitializing Neural Network Parameters ...\n')

initial_Theta1 = randInitializeWeights(input_layer_size, hidden_layer_size);
initial_Theta2 = randInitializeWeights(hidden_layer_size, num_labels);


% Unroll parameters
initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];


fprintf('\nTraining Neural Network... \n')

%  After you have completed the assignment, change the MaxIter to a larger
%  value to see how more training helps.
options = optimset('MaxIter', 100);

%  You should also try different values of lambda
lambda = 1;

nnCostFunction(initial_nn_params, input_layer_size, hidden_layer_size, num_labels, X, y, lambda)

% Create "short hand" for the cost function to be minimized
costFunction = @(p) nnCostFunction(p, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, X, y, lambda);

% Now, costFunction is a function that takes in only one argument (the
% neural network parameters)
[nn_params, cost] = fmincg(costFunction, initial_nn_params, options);

% Obtain Theta1 and Theta2 back from nn_params
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

fprintf('Program paused. Press enter to continue.\n');
pause;

save -binary -v7 weights.mat Theta1 Theta2
save -binary -v7 config.mat input_layer_size hidden_layer_size num_labels


nn_params = [Theta1(:); Theta2(:)];

nnCostFunction(nn_params, input_layer_size, hidden_layer_size, num_labels, X, y, lambda)

pred = predict(Theta1, Theta2, X);

fprintf('\nTraining Set Accuracy: %f\n', mean(double(pred == y)) * 100);

