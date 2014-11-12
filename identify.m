clear ; close all; clc

load('weights.mat');

data = load('unknow.txt');
x = data(1:end - 1);
y = data(end);

local = zeros(1, size(Theta2, 1));

local(y) = 1;

% y = local;

h1 = sigmoid(Theta1 * [1; x']);
h2 = sigmoid(Theta2 * [1; h1]);
[dummy, p] = max(h2);

index = 1;
all_extension = '';
fp = fopen('oct_extension.txt', 'r');
str = fgetl(fp);
while str != -1,
	all_extension = [all_extension; str];
	str = fgetl(fp);
	++index;
end

dummy;
p;
y;

fprintf('The correct rate is: %f\n', dummy)
fprintf('The extension of the file should be "%s"\n', ...
	all_extension(p, :))

