.PHONY: clean All

All:
	@echo "----------Building project:[ v1 -  ]----------"
	@cd "v1" && "$(MAKE)" -f  "v1.mk"
clean:
	@echo "----------Cleaning project:[ v1 -  ]----------"
	@cd "v1" && "$(MAKE)" -f  "v1.mk" clean
