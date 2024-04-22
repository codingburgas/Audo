# GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  Backend_config = debug
endif
ifeq ($(config),release)
  Backend_config = release
endif

PROJECTS := Backend

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

Backend:
ifneq (,$(Backend_config))
	@echo "==== Building Backend ($(Backend_config)) ===="
	@${MAKE} --no-print-directory -C Audo/Backend -f Makefile config=$(Backend_config)
endif

clean:
	@${MAKE} --no-print-directory -C Audo/Backend -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Backend"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"