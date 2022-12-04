// #ifndef __HEIMDALL_H
// #define __HEIMDALL_H

// #include <Arduino.h>
// #define HEAP_SIZE 0x2000
// #define MAGIC 0x7268

// namespace IbraKernel {
//     typedef struct {
//         size_t ChunkSize;
//         uint16_t Magic;
//     } CHUNK_HDR;
    
//     typedef struct {
//         size_t Size;
//         struct FREE_NODE *Next;
//     } FREE_NODE;
//     class Heimdall {
//         private:
//             static FREE_NODE *FreeList;
//         public:
//             Heimdall();
//             void Init();
//             void Reset();
//             void *Alloc(uint16_t Size);
//             void Free(uint16_t Size);
//     };
// };

// #endif