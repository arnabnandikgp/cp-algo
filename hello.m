% Create vectors 
x = [1 2 3 4];
y = [5 6 7 8];

% Add the vectors
z = x + y;

% Multiply element-wise
a = x .* y; 

% Matrix multiplication  
b = x*y.'; 

% Plot the vectors  
plot(x, y);

% Label plot
title('My Plot');
xlabel('x');
ylabel('y');

% Display variables
disp(z);
disp(a);
disp(b);