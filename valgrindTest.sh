#!/bin/bash

valgrind --leak-check=full listcar | grep "All heap blocks were freed"
