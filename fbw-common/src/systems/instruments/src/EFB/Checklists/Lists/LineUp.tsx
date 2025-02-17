// Copyright (c) 2023-2024 FlyByWire Simulations
// SPDX-License-Identifier: GPL-3.0

import { ChecklistDefinition } from '../Checklists';

export const lineUpChecklist: ChecklistDefinition = {
    name: 'LINE-UP',
    items: [
        {
            item: 'T.O. RWY',
            result: '_____(BOTH)',
        },
        {
            item: 'TCAS',
            result: '_____',
        },
        {
            item: 'PACKS 1 & 2',
            result: '_____',
        },
    ],
};
