.PHONY: clean All

All:
	@echo "----------Building project:[ led - Debug ]----------"
	@cd "led" && "$(MAKE)" -f  "led.mk"
clean:
	@echo "----------Cleaning project:[ led - Debug ]----------"
	@cd "led" && "$(MAKE)" -f  "led.mk" clean
