.PHONY: clean All

All:
	@echo "----------Building project:[ Test - Release ]----------"
	@cd "Test" && "$(MAKE)" -f  "Test.mk"
clean:
	@echo "----------Cleaning project:[ Test - Release ]----------"
	@cd "Test" && "$(MAKE)" -f  "Test.mk" clean
