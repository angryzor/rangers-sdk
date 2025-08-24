#pragma once

namespace hh::dv{
    class DvSceneNodeTree : public fnd::ReferencedObject{
    public:
        DvNodeBase* mainNode;
        DvParamUpdater* paramUpdater;
        DvSceneControl* parent;
        int diEventManagerDWORDC0;

        void FindNodeByType(DvNodeBase::NodeType type, DvNodeBase** result);
        DvNodeBase* FindNodeByGUID(char* guid, DvNodeBase* startNode);
        DvNodeBase* FindNodeByGUID(char* guid);
        DvNodeBase* GetMainNode() const;
        bool GetViewportDataByFrame(int currentFrame, hh::gfnd::ViewportData* returnValue);
        void InitializeClasses();
        void InitializeMainNode();
        void Update(int currentFrame);
        void PostUpdate(int currentFrame);

        DvSceneNodeTree(csl::fnd::IAllocator* allocator, DvSceneControl* dvSceneControl, int diEvtMgrUnk);
    };
}
