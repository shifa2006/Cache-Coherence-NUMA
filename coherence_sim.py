import sys

def simulate(protocol, iterations):
    states = ["I", "S", "E", "M", "O"]
    print(f"\n{protocol} Cache Coherence Simulation")
    print("-" * 40)

    for i in range(iterations):
        state = states[i % len(states)]
        print(f"Access {i + 1}: Cache State = {state}")

    print(f"\nTotal accesses: {iterations}")

for protocol in ["MSI", "MESI", "MOESI"]:
    simulate(protocol, int(sys.argv[1]) if len(sys.argv) > 1 else 10)
