//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------
#pragma once

#include "CommonMinMemory.h"

typedef _Return_type_success_(return >= 0) LONG NTSTATUS;
#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)

// === C Runtime Header Files ===
#include <time.h>
#if defined(_UCRT)
#include <cmath>
#else
#include <math.h>
#endif

// Exceptions
#include "Exceptions\Exceptionbase.h"
#include "Exceptions\OutOfMemoryException.h"

// Other Memory headers
#include "Memory\leakreport.h"
#include "Memory\AutoPtr.h"

// Other core headers
#include "Core\FinalizableObject.h"
#include "core\EtwTraceCore.h"
#include "core\ProfileInstrument.h"
#include "core\ProfileMemory.h"
#include "core\StackBackTrace.h"

#pragma warning(push)
#if defined(PROFILE_RECYCLER_ALLOC) || defined(HEAP_TRACK_ALLOC) || defined(ENABLE_DEBUG_CONFIG_OPTIONS)
#include <typeinfo.h>
#endif
#pragma warning(pop)

// Inl files
#include "Memory\Recycler.inl"
#include "Memory\MarkContext.inl"
#include "Memory\HeapBucket.inl"
#include "Memory\LargeHeapBucket.inl"
#include "Memory\HeapBlock.inl"
#include "Memory\HeapBlockMap.inl"

// Memory Protections
#ifdef _CONTROL_FLOW_GUARD
#define PAGE_EXECUTE_RW_TARGETS_INVALID   (PAGE_EXECUTE_READWRITE | PAGE_TARGETS_INVALID)
#define PAGE_EXECUTE_RW_TARGETS_NO_UPDATE (PAGE_EXECUTE_READWRITE | PAGE_TARGETS_NO_UPDATE)
#define PAGE_EXECUTE_RO_TARGETS_NO_UPDATE (PAGE_EXECUTE           | PAGE_TARGETS_NO_UPDATE)
#else
#define PAGE_EXECUTE_RW_TARGETS_INVALID   (PAGE_EXECUTE_READWRITE)
#define PAGE_EXECUTE_RW_TARGETS_NO_UPDATE (PAGE_EXECUTE_READWRITE)
#define PAGE_EXECUTE_RO_TARGETS_NO_UPDATE (PAGE_EXECUTE)
#endif
