function timeArrayAccess(size) {
    const arr = new Uint8Array(size);
    const iterations = 100000;
    const start = performance.now();
    for (let i = 0; i < iterations; i++) {
      for (let j = 0; j < size; j += 4096) {
        const val = arr[j];
      }
    }
    const end = performance.now();
    const avgTime = (end - start) / (iterations * (size / 4096));
    return avgTime;
  }
  
  const sizes = [1000000, 2000000, 4000000, 8000000, 16000000];
  for (let i = 0; i < sizes.length; i++) {
    const size = sizes[i];
    const time = timeArrayAccess(size);
    console.log(`Array size: ${size}, Average time per access: ${time.toFixed(20)}ms`);
  }