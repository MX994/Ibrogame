// #include "System/Heimdall.h"

// #include <stdio.h>
// #include <mman.h>

// IbraKernel::Heimdall::Heimdall() {
// }

// void IbraKernel::Heimdall::Init() {
//     if (FreeList != NULL) {
//         munmap(FreeList, HEAP_SIZE);
//         FreeList = NULL;
//         Reset();
//     }
// }

// void IbraKernel::Heimdall::Reset() {
//     if (FreeList == NULL) {
//         FreeList = (FREE_NODE *)mmap(NULL, HEAP_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
//         FreeList->Size = HEAP_SIZE - sizeof(FREE_NODE);
//         FreeList->Next = NULL;
//     }
//     return FreeList;
// }

// void *IbraKernel::Heimdall::Allocate(uint16_t Size) {
//     FREE_NODE **Previous, **Found;
//     CHUNK_HDR *Header;

//     while (*Found) {
//         if ((*Found)->Size >= size + sizeof(CHUNK_HDR)) {
//             break;
//         }
//         *Previous = *Found;
//         *Found = (*Found)->Next;
//     }

//     if (!Found) {
//         return NULL;
//     }

//     FREE_NODE *OriginalFreeBlock = *Found;
//     size_t TotalSize = Size + sizeof(CHUNK_HDR);
//     *Found = (FREE_NODE *)(((char *)*Found) + TotalSize);
//     (*Found)->Size = (OriginalFreeBlock)->Size - TotalSize;

//     if (!*Previous) {
//         FreeList = *Found;
//     } else {
//         (*Previous)->Next = *Found;
//     }
//     *Header = (CHUNK_HDR *)OriginalFreeBlock;
//     (*Header)->Size = Size;
//     (*Header)->Magic = MAGIC;

//     return ((char *)Header) + sizeof(CHUNK_HDR);
// }

// void IbraKernel::Heimdall::Free(void *Data) {
//     CHUNK_HDR *DataHdr = (CHUNK_HDR *)Data - 1;
//     FREE_NODE *DataNode = (FREE_NODE *)DataHdr;
//     DataNode->Size = DataHdr->Size;
//     DataNode->Next = FreeList;
//     FreeList = DataNode;

//     while (FreeList->Next) {
//         if ((char *)(FreeList + 1) + FreeList->Size == (char *)FreeList->Next) {
//             FreeList->Size += FreeList->Next->Size + sizeof(FREE_NODE);
//             FreeList->Next = FreeList->Next->Next;
//         }
//     }
// }
