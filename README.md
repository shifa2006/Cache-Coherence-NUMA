# Cache-Coherence-NUMA
Cache Coherence Protocol Simulation and NUMA Memory Performance Analysis

# Cache Coherence and NUMA Memory Performance Analysis

## 1. Introduction

This project focuses on understanding cache coherence protocols and analyzing memory performance in a multi-threaded environment.

It demonstrates three cache coherence protocols — MSI, MESI, and MOESI — and explores false sharing and NUMA memory access using C, Python, OpenMP, and Linux tools.

## 2. Objectives

- Understand MSI, MESI, and MOESI cache coherence protocols.
- Simulate cache state transitions.
- Study the effect of false sharing.
- Compare adjacent and padded memory layouts.
- Analyze memory access performance using multiple threads.
- Understand NUMA architecture and memory allocation.

## 3. Technologies Used

| Technology | Purpose |
|---|---|
| Ubuntu Linux | Practical environment |
| VMware Workstation | Virtual machine |
| C | Performance programs |
| Python 3 | Cache coherence simulation |
| GCC | Compilation |
| OpenMP | Multi-threading |
| numactl | NUMA memory control |
| hwloc | Hardware topology information |

## 4. Experiments Performed

### Experiment 1: Cache Coherence Simulation

Implemented simulations of:
- MSI
- MESI
- MOESI

The simulation displays cache state changes and counts bus transactions, invalidations, writebacks, and cache-to-cache transfers.

### Experiment 2: False Sharing

Compared two memory layouts:

- **Adjacent:** Counters are stored close together.
- **Padded:** Counters are separated to reduce false sharing.

The execution time and counter correctness are compared.

### Experiment 3: NUMA Memory Performance

- Checked the system's NUMA topology.
- Performed local memory access testing.
- Compared memory sweep execution with different thread counts.
- Examined the availability of remote NUMA nodes.

**Note:** The VMware environment exposed only one NUMA node. Therefore, remote NUMA memory comparison was not possible in this environment.

### Experiment 4: Performance Comparison

Compared adjacent and padded counter layouts using 1, 2, and 4 threads. Also measured memory sweep performance using different thread counts.

## 5. Project Files

| File | Description |
|---|---|
| `coherence_sim.py` | MSI, MESI, MOESI simulation |
| `false_sharing.c` | False sharing demonstration |
| `numa_sweep.c` | NUMA memory sweep |
| `compare_numa.c` | Performance comparison |

## 6. Results

### False Sharing Comparison

The experiment showed that padded counters performed faster than adjacent counters in the observed test run.

### Memory Sweep

The 2-thread memory sweep was faster than the 1-thread run in the observed test.

### NUMA Observation

The virtual machine detected only one NUMA node, so only local NUMA memory access could be tested.

## 7. Screenshots

### 1. VMware and Ubuntu Setup

![VMware Ubuntu Setup](<img width="920" height="1016" alt="01_ubuntu_setting" src="https://github.com/user-attachments/assets/fe54463e-c64a-4f65-96cd-90110e4a7b63" />
)

![Ubuntu Desktop](<img width="1280" height="760" alt="02_Ubuntu_Desktop png" src="https://github.com/user-attachments/assets/7a5c50fb-8271-45d2-b9e0-bb6ee51fa052" />
)

### 2. Software Installation and Verification

![Software Installation](<img width="707" height="561" alt="03_Software_Installation png" src="https://github.com/user-attachments/assets/be3f3f69-e92f-48c4-8e40-7e9a84222aab" />
)

![GCC and OpenMP Verification](<img width="710" height="546" alt="04_GCC_OpenMP_Verification png" src="https://github.com/user-attachments/assets/709a4a3c-4c6e-4b89-8862-672daa36c4b3" />
)

### 3. NUMA Hardware Information

![NUMA Topology](<img width="1102" height="385" alt="05_NUMA_Topology png" src="https://github.com/user-attachments/assets/43d1410a-06b8-4950-93f1-417d478313d1" />
)

### 4. Cache Coherence Simulation

![MSI MESI MOESI](<img width="1281" height="753" alt="06_MSI_MESI_MOESI png" src="https://github.com/user-attachments/assets/7d49b430-2590-45e6-9de0-b5522f278e03" />
<img width="1250" height="753" alt="07_MSI_MESI_MOESI png" src="https://github.com/user-attachments/assets/32cf2f1e-7fac-46f6-88b0-b25af732678f" />
<img width="1281" height="760" alt="08_MSI_MESI_MOESI png" src="https://github.com/user-attachments/assets/900b9b65-79ca-426a-b108-9a3ca83f984d" />

)

### 5. False Sharing Experiment

![False Sharing](<img width="1267" height="742" alt="09_False_Sharing png" src="https://github.com/user-attachments/assets/40dff23b-228e-4494-bb28-6a5622e7ded2" />)

### 6. Compilation

![Program Compilation](<img width="1181" height="295" alt="10_Program_Compilation png" src="https://github.com/user-attachments/assets/4903c63b-5fa3-4c5d-bed3-7b55992a95d7" />
)

### 7. Performance Comparison

![Comparison Results](<img width="921" height="381" alt="11_Comparison_Results png" src="https://github.com/user-attachments/assets/ef743603-b1a5-4213-989b-4632638ce9cf" />
)

## 8. Conclusion

This practical helped in understanding cache coherence protocols, false sharing, multi-threaded execution, and NUMA memory access.

The experiments demonstrated how memory layout and thread count can affect program performance. It also showed the limitations of performing remote NUMA testing in a single-node virtual machine.
