import os
import sys
import matplotlib.pyplot as plt
import numpy as np

sizes_file_path = os.path.join(os.getcwd(), "input.txt")

if not os.path.isfile(sizes_file_path):
    print("Missing input file")
    sys.exit(1)

data_dir = os.path.join(os.getcwd(), "output")

if not os.path.isdir(data_dir):
    print("Missing data directory")

x = []
yqs = []
ys = []

try:
    with open(sizes_file_path, "r") as sizes_file:
        lines = sizes_file.readlines()

        for line in lines:
            line = line.strip()
            x.append(int(line))

    sizes_file.close()

    data_file_names = os.listdir(data_dir)
    for data_file_name in data_file_names:
        data_file_path = os.path.join(data_dir, data_file_name)

        with open(data_file_path, "r") as data_file:
            y1 = []
            y2 = []
            y3 = []

            header = data_file.readline().strip()
            algname = header.split(" ")[0]

            for line in data_file:
                line = line.strip().split(" ")

                y1.append(int(line[1]))
                y2.append(int(line[2]))
                y3.append(float(line[3]))

            sublist = [header, y1, y2, y3]
            yqs.append(sublist)
        data_file.close()

    image_dir = os.path.join(os.getcwd(), "images")

    plt.title("Comparisons")
    for _y in yqs:
        plt.plot(x, _y[1], label=_y[0])
    plt.ylabel("Records Compared")
    plt.xlabel("List Size")
    plt.legend()

    image_path = os.path.join(image_dir, "comparisons.png")
    plt.savefig(image_path)
    plt.clf()

    plt.title("Copies")
    for _y in yqs:
        plt.plot(x, _y[2], label=_y[0])
    plt.ylabel("Records Copied")
    plt.xlabel("List Size")
    plt.legend()

    image_path = os.path.join(image_dir, "copies.png")
    plt.savefig(image_path)
    plt.clf()

    plt.title("Execution Time")
    for _y in yqs:
        plt.plot(x, _y[3], label=_y[0])
    plt.ylabel("Time in seconds")
    plt.xlabel("List Size")
    plt.legend()

    image_path = os.path.join(image_dir, "time.png")
    plt.savefig(image_path)
    plt.clf()

except Exception as e:
    print(f"Error: {e}")
