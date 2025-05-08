CXX      := g++
CXXFLAGS := -std=c++20 -Wall -Wextra

BINDIR   := bin

MODULES   := $(patsubst %/,%,$(wildcard */))

.PHONY: all
all: $(addprefix $(BINDIR)/,$(MODULES))

$(BINDIR)/%: %/main.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -I$* -o $@ $<

$(BINDIR)/%: %/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -I$* -o $@ $<

$(BINDIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -f $(addprefix $(BINDIR)/,$(MODULES))


.PHONY: run-%
run-%: $(BINDIR)/%
	./$(BINDIR)/$* < $*/input.txt > $*/output.txt
