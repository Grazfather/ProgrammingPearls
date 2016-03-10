import sys
import matplotlib.pyplot as plt

input = sys.stdin.read()

x = {
    '0': {"name": "reverse", "input": []},
    '1': {"name": "shuffle", "input": []},
    '2': {"name": "recursive", "input": []}
}
for l in input.split("\n")[:-1]:
    l = l.split(",")
    x[l[0]]["input"].append(l[1])

r = range(1, len(x["0"]["input"]) + 1)

for run in x.values():
    plt.plot(r, run["input"], label=run["name"])

plt.legend()
plt.savefig("plot.png")
