--- src/libcore/thread.cpp.orig	2015-07-15 10:37:38 UTC
+++ src/libcore/thread.cpp
@@ -27,10 +27,13 @@
 #include <boost/thread/thread.hpp>
 
 // Required for native thread functions
-#if defined(__LINUX__)
+#if defined(__LINUX__) && !defined(__FreeBSD__)
 # include <sys/prctl.h>
-#elif defined(__OSX__)
+#elif defined(__OSX__) || defined(__FreeBSD__)
 # include <pthread.h>
+# if defined(__FreeBSD__)
+#  include <pthread_np.h>
+# endif
 #elif defined(__WINDOWS__)
 # include <windows.h>
 #endif
@@ -70,7 +73,7 @@ void SetThreadName(const char* threadNam
 } // namespace
 #endif // _MSC_VER
 
-#if defined(__LINUX__) || defined(__OSX__)
+#if defined(__LINUX__) || defined(__OSX__) || defined(__FreeBSD__)
 static pthread_key_t __thread_id;
 #elif defined(__WINDOWS__)
 __declspec(thread) int __thread_id;
@@ -92,7 +95,7 @@ struct Thread::ThreadPrivate {
 	static ThreadLocal<Thread> *self;
 	bool critical;
 	boost::thread thread;
-	#if defined(__LINUX__) || defined(__OSX__)
+	#if defined(__LINUX__) || defined(__OSX__) || defined(__FreeBSD__)
 		pthread_t native_handle;
 	#endif
 
@@ -157,7 +160,7 @@ bool Thread::getCritical() const {
 int Thread::getID() {
 #if defined(__WINDOWS__)
 	return __thread_id;
-#elif defined(__OSX__) || defined(__LINUX__)
+#elif defined(__OSX__) || defined(__LINUX__) || defined(__FreeBSD__)
 	/* pthread_self() doesn't provide nice increasing IDs, and syscall(SYS_gettid)
 	   causes a context switch. Thus, this function uses a thread-local variable
 	   to provide a nice linearly increasing sequence of thread IDs */
@@ -240,7 +243,7 @@ bool Thread::setPriority(EThreadPriority
 	if (!d->running)
 		return true;
 
-#if defined(__LINUX__) || defined(__OSX__)
+#if defined(__LINUX__) || defined(__OSX__) || defined(__FreeBSD__)
 	Float factor;
 	switch (priority) {
 		case EIdlePriority: factor = 0.0f; break;
@@ -320,9 +323,9 @@ void Thread::setCoreAffinity(int coreID)
 	if (!d->running)
 		return;
 
-#if defined(__OSX__)
+#if defined(__OSX__) || defined(__FreeBSD__)
 	/* CPU affinity not supported on OSX */
-#elif defined(__LINUX__)
+#elif defined(__LINUX__) && !defined(__FreeBSD__)
 	int nCores = sysconf(_SC_NPROCESSORS_CONF),
 	    nLogicalCores = nCores;
 
@@ -425,7 +428,7 @@ void Thread::dispatch(Thread *thread) {
 	#endif
 
 	int id = atomicAdd(&__thread_id_ctr, 1);
-	#if defined(__LINUX__) || defined(__OSX__)
+	#if defined(__LINUX__) || defined(__OSX__) || defined(__FreeBSD__)
 		pthread_setspecific(__thread_id, reinterpret_cast<void *>(id));
 		thread->d->native_handle = pthread_self();
 	#elif defined(__WINDOWS__)
@@ -439,13 +442,15 @@ void Thread::dispatch(Thread *thread) {
 
 	if (!thread->getName().empty()) {
 		const std::string threadName = "Mitsuba: " + thread->getName();
-#if defined(__LINUX__)
+#if defined(__LINUX__) && !defined(__FreeBSD__)
 		// Disabled for now, since it is not yet widely available in glibc
 		// pthread_setname_np(pthread_self(), threadName.c_str());
 
 		prctl(PR_SET_NAME, threadName.c_str());
 #elif defined(__OSX__)
 		pthread_setname_np(threadName.c_str());
+#elif defined(__FreeBSD__)
+		pthread_set_name_np(pthread_self(), threadName.c_str());
 #elif defined(__WINDOWS__)
 		SetThreadName(threadName.c_str());
 #endif
@@ -541,7 +546,7 @@ void Thread::staticInitialization() {
 			__omp_threadCount = omp_get_max_threads();
 		#endif
 	#endif
-	#if defined(__LINUX__) || defined(__OSX__)
+	#if defined(__LINUX__) || defined(__OSX__) || defined(__FreeBSD__)
 		pthread_key_create(&__thread_id, NULL);
 	#endif
 	detail::initializeGlobalTLS();
@@ -588,7 +593,7 @@ void Thread::staticShutdown() {
 	delete ThreadPrivate::self;
 	ThreadPrivate::self = NULL;
 	detail::destroyGlobalTLS();
-#if defined(__LINUX__) || defined(__OSX__)
+#if defined(__LINUX__) || defined(__OSX__) || defined(__FreeBSD__)
 	pthread_key_delete(__thread_id);
 #endif
 #if defined(__OSX__)
@@ -637,16 +642,18 @@ void Thread::initializeOpenMP(size_t thr
 			}
 			const std::string threadName = "Mitsuba: " + thread->getName();
 
-			#if defined(__LINUX__)
+			#if defined(__LINUX__) && !defined(__FreeBSD__)
 				prctl(PR_SET_NAME, threadName.c_str());
 			#elif defined(__OSX__)
 				pthread_setname_np(threadName.c_str());
+			#elif defined(__FreeBSD__)
+				pthread_set_name_np(pthread_self(), threadName.c_str());
 			#elif defined(__WINDOWS__)
 				SetThreadName(threadName.c_str());
 			#endif
 
 			int id = atomicAdd(&__thread_id_ctr, 1);
-			#if defined(__LINUX__) || defined(__OSX__)
+			#if defined(__LINUX__) || defined(__OSX__) || defined(__FreeBSD__)
 				pthread_setspecific(__thread_id, reinterpret_cast<void *>(id));
 			#elif defined(__WINDOWS__)
 				__thread_id = id;
