Multithreaded Optimized Storage Framework 
Efficient, Cache-Conscious, Low-Latency, Parallel Storage System in C++

Overview
This project aims to build a high-performance multithreaded storage framework that efficiently processes and stores continuous streams of data. The focus is on cache-conscious design, low-latency operations, and parallel execution across multiple CPU cores.

Designed for modern multi-core architectures, this framework optimizes data placement, access patterns, and threading strategies to achieve maximum throughput and minimal contention.

Key Features
1) Parallel Processing: Leverages multithreading to distribute data handling across CPU cores.
2) Low-Latency Storage: Optimized for minimal read/write latency using efficient buffering strategies.
3) Cache-Conscious Design: Exploits CPU cache locality to reduce memory bottlenecks.
4) Core Affinity Optimization: Assigns threads to specific CPU cores to maximize parallel efficiency.
5) Scalable & Modular: Designed to handle high-throughput workloads efficiently.
6) Built for MacBook Pro (Apple Silicon/Intel): Optimized for macOS with pthread and mach thread policies.

Technologies Used
C++20 - Efficient memory management, threading, and optimizations
POSIX Threads (pthread) - Fine-grained multithreading and CPU core pinning
Thread Affinity (mach_thread_self) - Core-aware task distribution (macOS)
Lock-Free Data Structures - Reduce contention and improve concurrency
SIMD Optimizations –-If applicable for data processing acceleration

Planned Optimizations
1) NUMA-Aware Memory Management for minimizing cross-core communication overhead.
2) I/O Optimization Techniques for efficient disk/memory access.
3) Prefetching & Caching Strategies to leverage CPU cache hierarchy.
4) Work-Stealing Scheduler to balance load across multiple worker threads.

Build & Run Instructions
macOS (Apple Silicon or Intel)
C++20 Compiler (Clang/GCC)
CMake (for build management)
