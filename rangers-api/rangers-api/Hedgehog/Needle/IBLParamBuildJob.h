#pragma once

namespace hh::needle {
    class IBLParamBuildJob : public ParamBuildJob {
    public:
        SCIBL* sceneContext;

        virtual void Prepare(ParameterValueObject* parameters, PipelineInfo* pipelineInfo) override;
        virtual void Run(ParamValueOverrideHelper* paramOverrides, PipelineInfo* pipelineInfo, unsigned int viewportId, unsigned int parameterId) override;
    };
}
