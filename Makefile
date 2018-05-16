.PHONY: clean All

All:
	@echo "----------Building project:[ Kriging - Release ]----------"
	@cd "Kriging" && "$(MAKE)" -f  "Kriging.mk"
clean:
	@echo "----------Cleaning project:[ Kriging - Release ]----------"
	@cd "Kriging" && "$(MAKE)" -f  "Kriging.mk" clean
