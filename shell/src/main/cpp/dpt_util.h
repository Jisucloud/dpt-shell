//
// Created by luoyesiqiu
//

#ifndef DPT_DPT_UTIL_H
#define DPT_DPT_UTIL_H
#include <jni.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <libzip/zip.h>
#include <libzip/zipint.h>
#include <stdlib.h>
#include <sys/prctl.h>
#include "dpt_log.h"
#include "JniWrapper.h"

#ifdef __LP64__
#define LIB_DIR "lib64"
#define pointer_t uint64_t
#else
#define LIB_DIR "lib"
#define pointer_t uint32_t
#endif

static AAssetManager *g_AssetMgrInstance = nullptr;
static jclass g_ContextClass = nullptr;

jclass getContextClass(JNIEnv *env);
AAssetManager *getAssetMgr(JNIEnv *env, jobject assetManager);
AAsset *getAsset(JNIEnv *env, jobject context, const char *filename);
jstring getApkPath(JNIEnv *env,jclass);
int endWith(const char *str,const char* sub);
void appendLog(const char* log);
void hexDump(const char* name,const void* data, size_t size);
void load_zip(const char* zip_file_path,void **zip_addr,off_t *zip_size);
void *read_zip_file_entry(const void* zip_addr,off_t zip_size,const char* entry_name,zip_uint64_t *entry_size);
int find_in_maps(const char* find_name,pointer_t *start,pointer_t *end,char *full_path);
const char* find_symbol_in_elf_file(const char *elf_file,int keyword_count,...);
void readPackageName(char *packageName);
jobject getActivityThreadInstance(JNIEnv *env);
void getClassName(JNIEnv *env,jobject obj,char *destClassName);
void parseClassName(const char *src, char *dest);
void printTime(const char* msg,clock_t start);
void getThreadName(char *threadName);
#endif //DPT_DPT_UTIL_H
