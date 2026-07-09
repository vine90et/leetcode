/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    const num = init;
    return{
        increment: ()=> {
            return ++init;
        },

        reset: ()=>{
            return init = num;
        },

        decrement: ()=>{
            return --init;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */