#include "stack.h"

/* 64-bit stack for eval and global stacks */

#define ERR_TYPE enum vm_err_code

stack_t* stack_new( size_t const size ) {
	stack_t* new_stack = malloc( sizeof(stack_t) );		

	*new_stack = (stack_t) {
		.size = size, .sp = 0,
		.data = malloc( sizeof(uint64_t) * size )
	};

	return new_stack;
}

int stack_is_full( stack_t const * const stack ) { return stack-> sp == stack-> size; }

int stack_is_empty( stack_t const * const stack ) { return stack-> sp == 0; }

ERR_TYPE stack_push( stack_t* const stack, uint64_t const value ) {
	if( stack_is_full(stack) ) return STACK_OF;
	stack-> data[ stack-> sp++ ] = value;	

	return OK;
}

ERR_TYPE stack_peek( stack_t* const stack, uint64_t * const var ) {
	if( stack_is_empty(stack) ) return STACK_IS_EMPTY;
	*var = stack-> data[ stack-> sp - 1 ];

	return OK;
}

ERR_TYPE stack_pop( stack_t* const stack, uint64_t * const var ) {
	ERR_TYPE err = stack_peek( stack, var );
	if(err) return err;
	stack-> sp--;
	
	return OK;
}

void stack_free_data( stack_t* const stack ) { free( stack-> data ); }

void stack_clear( stack_t* const stack ) { stack-> sp = 0; }


#ifdef STACK_TEST

int main( int argc, char** argv ) { 
	stack_t *new_stack = stack_new( 30 ); 
	uint64_t value;

	stack_push( new_stack, 34 );
	stack_push( new_stack, 16 );
	stack_peek( new_stack, &value );
	stack_pop( new_stack, &value );

	return value;
}

#endif

