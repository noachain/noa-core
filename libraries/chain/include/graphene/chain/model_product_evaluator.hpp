/*#ifndef MODEL_PRODUCT_EVALUATOR_HPP
#define MODEL_PRODUCT_EVALUATOR_HPP

#endif // MODEL_PRODUCT_EVALUATOR_HPP
*/
#pragma once
#include <graphene/chain/protocol/operations.hpp>
#include <graphene/chain/evaluator.hpp>
#include <graphene/chain/database.hpp>
#include <graphene/chain/model_product_object.hpp>

namespace  graphene
{
    namespace chain
    {
        class model_product_create_evaluator : public evaluator<model_product_create_evaluator>
        {
        public:
            typedef model_product_create_operation operation_type;
            void_result do_evaluate(const model_product_create_operation&o);
            object_id_type do_apply(const model_product_create_operation&o);

        };

        class model_product_update_evaluator : public evaluator<model_product_update_evaluator>
        {
        public:
            typedef model_product_update_operation operation_type;
            void_result do_evaluator(const model_product_update_operation&o);
            object_id_type do_apply(const model_product_update_operation&o);
        };
    }
}
