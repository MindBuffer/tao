		
The Tao Physical Modelling Sound Synthesis Program
--------------------------------------------------

Introduction
------------

Tao is a software package for sound synthesis using physical models. It
provides a virtual acoustic material based on point masses connected
together with springs from which a wide variety of virtual musical
instruments can be constructed. Tao can be used either as a stand-alone
tool or as a C++ library for those who wish to incorporate its
functionality into their own C++ programs or don't want to use the user
interface provided. 

Tao provides various objects such as bows, hammers, connectors and
outputs for exciting the instruments, coupling them together and 
generating sound output. One of the main features of Tao is its 3-D
graphics visualisations of the instrument constructed, showing how the
acoustic waves propagate through the instruments. 

Features
--------

The main features of Tao are:

- A physically modelled elastic material from which a wide variety
of virtual musical instruments can be constructed.

- The ability to produce very high quality `organic' sounds, i.e.
sounds which are much more `acoustic' than those usually produced
by digital synthesis.

- A set of virtual `devices' such as Bows, Hammers, Connectors and
Outputs for coupling together, exciting and generating output from
instruments.

- Real-time visualisations of the instruments showing in detail how
the waves propagate through the various componnents.

- A well documented C++ API for those who want to develop there own
programs making use of Tao's functionality (actually it is not
documented yet but that part is the next priority).

- A custom designed script language for creating and experimenting
with new instruments.

Requirements
------------

Tao has been built and tested on both Irix 6.2 and Red Hat Linux 5.0
(and more recently Red Hat 5.2 and 6.0). It requires X windows and OpenGL
compatible libraries and headers to be installed, either true OpenGL
or a clone such as Brian Paul's Mesa3D, and Mark Kilgard's GLUT (GL
Utility Toolkit) library and headers. It also requires Michael Pruett's
port of the SGI audiofile library in order to write WAV format soundfiles.

Finally it requires the following tools in order to build it from source.

    A C++ compiler      (preferably gnu g++ but the code should
                         compile perfectly well under others)
    flex or lex         (lexical analyser generator)
    bison or yacc       (parser generator)
    Doxygen             (a tool for generating documentation from
                         C++ sources)
    Hyperlatex          (a tool for generating multi-format
                         documentation from LaTeX sources)

You only need Doxygen and Hyperlatex if you intend to build the
documentation from the sources. Please note that even if you download
a binary distribution, you will still need a C++ compiler since Tao
uses the compiler every time a script is run.

Tao works with both OpenGL and Mesa3D since the rendering used does
not rely upon any advanced or esoteric features.

For Mesa3D headers, libraries and examples go to

    www.mesa3d.org

If you are using Mesa3D then you should get the GLUT libraries and
headers thrown in for convenience. If not then go to

    http://reality.sgi.com/opengl/

and look for `GLUT'

For the audiofile library package go to

    http://www.68k.org/ michael/audiofile/


Steps for installation
----------------------

As with most GNU style software there are 3 easy steps to installing
Tao. First change to the directory where you have unpacked Tao and
type:

    ./configure
    make
    make install

The default path for installation of the binaries, library files and
shell scripts is /usr/local, so you will need root access in order
to use the default. If you do not have root access then change the
above to

     ./configure --prefix=<your path>

where <your path> is the full path to wherever you want to install Tao.

The `configure' part checks to see if you have the necessary programs
headers and libraries installed. If you do not the configuration will
abort with a message telling you what is missing. See the earlier
part of this README for details on where to get the components you
need in order to use Tao.


Troubleshooting the configuration process
-----------------------------------------

If the configure script failed it should give you some feedback about
what it couldn't find on your system. Some things to watch out for
are:

- Check the value of the LD_LIBRARY_PATH environment variable. This
is used to tell your system where to look for libraries which are
not installed in /usr/lib. Quite often packages which you install
yourself will install libraries in /usr/local/lib by default. If 
LD_LIBRARY_PATH doesn't point to this directory (or wherever else
the library files are installed) then none of your programs which
require these libraries will ever find them. For Mesa this means
'libMesaGL.so' or 'libGL.so' and 'libMesaGLU.so' or 'libGLU.so'
and for GLUT, 'libglut.so'.

To find out the value of LD_LIBRARY_PATH type:

    echo $LD_LIBRARY_PATH

If the value of LD_LIBRARY_PATH doesn't contain '/usr/local/lib'
(or any of the paths where your libraries are located) then you
must update it so that it does. First, to find out what shell you
use type:

    echo $SHELL

If the answer is '/bin/bash' go to the section entitled 'if you use
the /bin/bash shell' below for details of how to amend the value of
LD_LIBRARY_PATH.

If the answer is '/bin/tcsh' go to the section entitled 'if you use
the /bin/tcsh shell' below for details of how to amend the value of
LD_LIBRARY_PATH.


- A friend who tried to install Tao on a freshly installed Red Hat
6.1 system ran into problems with the audiofile library. This
turned out to be due to the fact that there was no 'libaudiofile.so'
file. Usually shared libraries have a symbolic link from the
base name of the library file to the actual version used. So for
example on my system (Red Hat 6.0) the command

    cd /usr/lib; ls -l libaudio*

reveals the following symbolic links:

    libaudiofile.a
    libaudiofile.so -> libaudiofile.so.0.0.0
    libaudiofile.so.0 -> libaudiofile.so.0.0.0
    libaudiofile.so.0.0.0

If you do not have a file named 'libaudiofile.so' you must create
a symbolic link. To do this, become root (or talk to your system
administrator) and in /usr/lib type:

    ln -s libaudiofile.0.0.0 libaudiofile.so

This also holds for any of the other libraries required by Tao. If
the configure script says that it can't find one or more of the
libraries and you have already checked the value of LD_LIBRARY_PATH
you may want to check to see that each library correctly has a plain
'.so' file linked to the appropriate version of the file with the
version numbers after it. If not then create a symbolic link for
each missing one as described above.

Continuing with the build process
---------------------------------
	
Assuming the `make' and `make install' parts work OK you should now
have the following files installed (I will assume that prefix=/usr/local)

    /usr/local/
        
        lib/
            libtao.so*
            libtao.a

        bin/
            tao
            tao-config
            taosf
            taoparse
            tao2aiff

The install process leaves Tao's header files where they are but
provides a shell script 'tao-config' which can be used to find out
where both these headers and the various libraries are installed.
This is particularly useful if you want to write your own C++ programs
and link them against the Tao libraries. It is used in the following
way:

    tao-config --prefix     =>  location for installed files
    tao-config --includes   =>  command line flags for the compiler
                                to find Tao's header files
    tao-config --libs       =>  command line flags for the compiler
                                to find Tao's libraries

The next step is VERY IMPORTANT - in order for your system to locate
the binary executables, shell scripts and libraries you have to set
two environment variables, PATH and LD_LIBRARY_PATH. This process is
described in detail below.

Firstly though type echo $SHELL to see which shell your system uses
by default.

If you use the `/bin/bash' shell
--------------------------------

Type the following to see if '/usr/local/lib' is already in your path:

    echo $PATH

If not then open the '.bash_profile' file in your home directory and
add the following lines:

    PATH=$PATH:/usr/local/bin
    export PATH

Then type the following to see if '/usr/local/lib' is in your
library loading path:

    echo $LD_LIBRARY_PATH

If not then add the following lines to the '.bash_profile' file in
your home directory:

    LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
    export LD_LIBRARY_PATH
        

If you use the `/bin/tcsh' shell
--------------------------------

Type the following to see if '/usr/local/bin' is in your path:

    echo $PATH

If not then add the following line to the '.tcshrc' file in
your home directory:

    setenv PATH $PATH:/usr/local/bin

Then type the following to see if '/usr/local/lib' is in your
library loading path:

    setenv | grep LD_LIBRARY_PATH

If not then add the following line to the '.tcshrc' file in
your home directory:

    setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH:/usr/local/lib

 
Testing Tao
-----------

Assuming that everything went OK with the build and installation the
next step is to test that everything is working. To do this copy the
file `test.tao' from the `examples' directory into your home directory
and type:

    tao test

Tao should respond with the following messages:

    ========================================
    |     Tao (c) 1996-99 Mark Pearson     |
    | Sound Synthesis with Physical Models |
    ========================================

    Processing test.tao
    Making test.exe
    Executing test.exe

    Sample rate=44100 KHz
    Score duration=20 seconds                

You should then see Tao's instrument visualisation window open. When
this window opens initially Tao is in 'pause' mode. This gives you
time to move, rotate and zoom the image before setting the synthesis
in motion. To unpause Tao press the [right-arrow] cursor key. This
should set the instrument in motion. For more information on what to
do next refer to the User Manual.
