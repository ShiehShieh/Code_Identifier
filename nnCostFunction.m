function [J grad] = nnCostFunction(nn_params, ...
				   input_layer_size, ...
				   hidden_layer_size, ...
				   num_labels, ...
				   X, y, lambda)

m = size(X, 1);

J = 0;

Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

m = size(X, 1);
         
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));


local = zeros(m, size(Theta2, 1));

for index = 1:m,
	local(index, y(index)) = 1;
end;

y = local;
X = [ones(m, 1) X];
prediction = sigmoid(Theta2 * ([ones(m, 1) sigmoid(Theta1 * X')']')); 
local1 = Theta1;
local2 = Theta2;
local1(:, 1) = zeros(size(Theta1, 1), 1);
local2(:, 1) = zeros(size(Theta2, 1), 1);

% Cost Function
J = (1 / m) * sum(sum((-y) .* log(prediction') - (1 - y) .* log(1 - prediction'))) + (lambda / (2 * m)) * (sum(sum(local1.^2)) + sum(sum(local2.^2)));

delta1 = zeros(size(Theta1));
delta2 = zeros(size(Theta2));
for index = 1:m,
	activation1 = X(index, :);
	z2 = Theta1 * activation1';
	activation2 = sigmoid(z2);
	z3 = Theta2 * ([1 activation2'])';
	activation3 = sigmoid(z3);
	error_term3 = activation3 - y(index, :)';
	error_term2 = Theta2' * error_term3.*sigmoidGradient(([1 z2'])');
	delta1 = delta1 + error_term2(2:end)*activation1;
	delta2 = delta2 + error_term3*[1; activation2]';
end;

% Gradient of Theta (Partial Derivative)
Theta1_grad = (delta1 + lambda * [zeros(size(Theta1, 1), 1) Theta1(:, 2:end)]) / m;
Theta2_grad = (delta2 + lambda * [zeros(size(Theta2, 1), 1) Theta2(:, 2:end)]) / m;


% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end

