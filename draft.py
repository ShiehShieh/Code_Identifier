def load_data(input_path, n):
    """TODO: Docstring for load_data.
    :returns: TODO

    """
    X, y          = [], []
    all_files     = [x for x in os.listdir(input_path) if x[0] != '.']
    temp          = set([re.sub('(^\.h$)|(^\.cc$)|(^\.c$)', '.cpp', os.path.splitext(x)[1]) \
                        for x in all_files])
    all_extension = {}

    for file_name in all_files:
        extension = re.sub('(^\.h$)|(^\.cc$)|(^\.c$)', '.cpp', os.path.splitext(file_name)[1])
        all_extension.setdefault(extension, operator.indexOf(temp, extension))

        with open(input_path + file_name, 'r') as a_file:
            label    = []
            raw_data = [ord(x) for x in a_file.read(n)]
            if len(raw_data) < n:
                raw_data = raw_data + [32] * (n - len(raw_data))

            for index in range(len(temp)):
                label.append(0)
            label[all_extension[extension]] = 1

            X.append(raw_data)
            y.append(label)

    with open('./parameters/all_extension.txt', 'w') as extension_file:
        extension_file.write(json.dumps(all_extension))

    X, y = numpy.array(X), numpy.array(y)

    return X, y


theta1 = shared(value=params[0])
b1 = shared(value=params[1])
theta2 = shared(value=params[2])
b2 = shared(value=params[3])
neuron = T.nnet.sigmoid(T.dot(X, theta1) + b1)
prediction = T.dot(neuron, theta2) + b2
pred = theano.function([], [prediction])


with open('all_extension.txt', 'w') as extension_file:
    extension_file.write(json.dumps(all_extension))

with open('all_keywords.txt', 'w') as keyword_file:
    keyword_file.write(json.dumps(all_keywords))

with open('oct_extension.txt', 'w') as oct_extension:
    for extension in all_extension:
        oct_extension.write(extension + os.linesep)

