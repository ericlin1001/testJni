all: run

compile: *.java
	javac *.java
	# generate c header files.
	javah HelloJNI
	# then implment in .c file.s

buildSO: *.cpp *.h
	g++ -shared -fPIC -o libhello.so *.cpp
	nm libhello.so|grep sayHello

run: compile buildSO
	java -Djava.library.path=. HelloJNI

.PHONY:all compile buildSO run clean


clean:
	/bin/rm -f *.so *.out *.class
