# target & input files

obj-m := pr_test.o
obj-m += pr_modex.o
obj-m += pr_moddep.o
obj-m += pr_moddep1.o
obj-m += pr_modexfunc.o
obj-m += pr_depfunc.o
obj-m += pr_myhello.o 
obj-m += pr_depfunc1.o
obj-m += pr_modparam.o
obj-m += pr_procinfo.o
#obj-m += pr_structmm.o
obj-m += pr_currinfo.o

# variable/macro to hold kernel headers directory path
KDIR= /lib/modules/$(shell uname -r)/build

# command to convert input files into desired target 
# this command uses kbuild scripts found in kernel header folder 
all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

install:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules_install

clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
