/*#ifndef POWER_PRODUCT_EVALUATOR_H
#define POWER_PRODUCT_EVALUATOR_H

#endif // POWER_PRODUCT_EVALUATOR_H
*/
#pragma once
#include <graphene/chain/protocol/operations.hpp>
#include <graphene/chain/evaluator.hpp>
#include <graphene/chain/database.hpp>
#include <graphene/chain/power_product_object.hpp>
namespace graphene
{
    namespace chain
    {
        class power_product_create_evaluator : public evaluator<power_product_create_evaluator>
        {
        public:
            typedef power_product_create_operation operation_type;
            void_result do_evaluate(const power_product_create_operation&o);
            object_id_type do_apply(const power_product_create_operation&o);
        };

        class power_product_update_evaluator : public evaluator<power_product_update_evaluator>
        {
        public:
            typedef power_product_update_operation operation_type;
            void_result do_evaluate(const power_product_update_operation&o);
            object_id_type do_apply(const power_product_update_operation&o);
        };
    }
}
